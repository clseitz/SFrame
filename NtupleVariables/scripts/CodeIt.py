#!/usr/bin/python
# -*- coding: iso-8859-15 -*-
#
#
#   @short: Create code f???r reading in the variables from ntuples into the Ntuple objects.
#
#  @author: Alexander Mann (85) <mann@cern.ch> or <amann@uni-goettingen.de>
#
# @version: $Id: CodeIt.py 494 2010-07-30 13:41:32Z svn $
#
#

import os, sys
import string, re
import itertools


class Templater:


  def __init__(self, objectname, variablefile):
    "constructor, reads in variablefile"
    
    self.subst_table = {
      'Program': 'Code produced by $Id: CodeIt.py 494 2010-07-30 13:41:32Z svn $'.replace('$', ''),
      'AUTO_WARNING': 'THIS FILE HAS BEEN GENERATED AUTOMATICALLY. DO NOT EDIT DIRECTLY, CHANGES WILL BE LOST UPON NEXT CODE GENERATION.',
      'Object': objectname,
    }
    self.variables = []
    self.use_dl    = False
    
    # read variable list
    index = 1
    allconnects = []
    for line in file(variablefile).readlines():
      if line[0] == '#':
        continue
      items = re.sub('\s+',' ',line).strip().split(" ")
      # re-merge vectors
      openBracket = -1
      closeBracket = -1
      # print "items after re.sub", items
      for i in range(len(items)):
        if (items[i].find("<") >= 0) and (openBracket == -1):
          openBracket = i
        if (items[i].find(">") >= 0):
          closeBracket = i
      if (openBracket != -1):
        items[openBracket:closeBracket+1] = [' '.join(items[openBracket:closeBracket+1])]
      # print "items after re.sub and re-merge", items
      if len(items) < 3:
        continue
      vars = dict(itertools.izip(["dl", "type", "name"], items))
      for more in items[3:]:
        # do other cases here
        vv = more.split("=")
        if len(vv) == 1:
          vars["default"] = more
        else:
          vars[vv[0]] = vv[1]
      vars["index"] = str(index)
      if not 'default' in vars:
        vars['default'] = "0"
      if not 'usename' in vars:
        vars['usename'] = vars['name']
      if vars['usename'] in allconnects:
        print 'ERROR:', objectname, '->', vars['usename'], 'cannot be connected twice (would give segfault)'
        self.__abort()
      allconnects.append(vars['usename'])
      self.variables.append(vars)
      index = index + 1
      
    # sort by detail level
    self.variables.sort(cmp=lambda x,y: cmp(x['dl'], y['dl']))
#    for e in self.variables:
#      print e
  
  def __abort(self):
    "unsuccessful completion, print warning and exit"
    print "\n\tAborting code generation due to error, code is not complete.\n"
    sys.exit(1)
    
    
  def AddSubst(self, addsubst):
    "put additional entries into the substitution dictonary"
    self.subst_table.update(addsubst)
    
  
  def Use_DL(self, use_dl):
    self.use_dl = use_dl

    
  def CodeIt(self, input_template, output_name):
    "main part, opening files, calling generator functions"
    print "Starting code generation into", output_name
    if not self.use_dl:
      print "  Detail levels disabled"
    if not os.path.exists(input_template):
      print "Input file", input_template, "does not exist"
      sys.exit(1)
    inf  = file(input_template, 'r')
    outf = file(output_name, 'w')
    # cannot match multiple lines:
    #for inline in inf.readlines():
    #  outline = self.GeneralReplace(inline)
    #  outline = re.sub(r'(?ms)\$\{\{(.*?)(:.*?)?\}\}', self.CodeInserter, outline)
    #  outf.write(outline)
    inline = inf.read()
# doesnt work    re.sub(r'(?ms)\@\{\{(.*?)(:.*?)?\@\}\}',"\n",inline) #remove comments like @{{ comment @}} 
    outline = self.GeneralReplace(inline)
    outline = re.sub(r'(?ms)\$\{\{(.*?)(:.*?)?\}\}', self.CodeInserter, outline)
    outline = outline.replace('\r','')
    outf.write(outline)
    inf.close()
    outf.close()  
    

  def GeneralReplace(self, inline):
    "general replace according to subst_table"
    s = string.Template(inline)
    return s.safe_substitute(self.subst_table)
    
    
  def CodeInserter(self, inserter):
    "more sophisticated parts with code generation, this function only passes on to the actual code generations functions"
    creators = {
      'AllBasics' : self.AllBasics,
      'AllVars'   : self.AllVars,
      'AllVarsDL' : self.AllVarsDL,
      'PrintAllVarsDL' : self.PrintAllVarsDL,
      'AllNoBools': self.AllNoBools,
      'AllBools'  : self.AllBools,
      'Only'      : self.Only,
      'Enums'     : self.Enums,
    }
    name = inserter.group(1)
    args = inserter.group(2).lstrip(":")
    if not name in creators:
      print "ERROR:", name, "is not a valid placeholder"
      return 'ERROR'
    if args:
      return creators[name](args)
    else:
      return creators[name]()
      
      
  def Only(self, args):
    """${{Only:xx: ...}} marks parts which should be included only for certain objects
    xx is a comma-seperated list of object names.
    """
    args = args.split(":", 1)
    if len(args) < 2:
      print 'Syntax error in Only argument: expected ":" after object name'
      return ""
    objlist = args[0].rstrip(':').split(",")
    if self.subst_table['Object'] in objlist:
      return args[1]
    else: 
      return ''
    
  
  def AllBasics(self, args):
    "replicates lines for the basic variables"
    if 'NoBasics' in self.subst_table:
      return ''
    result = ""
    for name in ['e', 'pt', 'eta', 'phi', 'm']:
      line = args
      line = line.replace("#name#", name)
      result = result + line + "\n"
    return result
    
  
  def AllVars(self, args):
    "replicates a line for all variables"
    result = ""
    for vars in self.variables:
      line = args    
      for key in vars.keys():
        line = line.replace("#%s#" % key, vars[key])
      if line.find("NOPOINTER") > 1:
        if vars['type'] != 'bool':
          line = line.replace(vars['type'],vars['type'].strip("*"),1)
        else:
          line = line.replace("*(","(",1)
        line = line.replace("NOPOINTER",'')
      result = result + line + "\n"  
    return result
  
  
  def AllVarsDL(self, args):
    "like AllVars, but with surrounding if statements"
    result = ""
    lastdl = 0
    first = True
    args = args.split(":")
    if len(args) < 2:
      print 'Syntax error in AllVarsDL argument'
      return ""
    what = args[0]
    prefix = ""
    if len(args) > 2:
      prefix = args[1]
    args = args[len(args)-1]
    if not self.use_dl:
      return self.AllVars(args)
    for vars in self.variables:
      line = args
      dl   = vars['dl'] # dl   = int(vars['dl'])
      if dl != lastdl:
        if not first:
          result = result + "} // end of detail level %s\n\n" % lastdl
        first = False
        result = result + "if( "
        for i,detlev in enumerate(dl.split(',')): 
          if i: result += " || "
          result += " ((%s & Ntuple::%s%s) == Ntuple::%s%s) " % (what, objectname, detlev, objectname, detlev)
        result = result + " ) {\n"
        #result = result + "if( (%s & Ntuple::%s%s) == Ntuple::%s%s ) {\n" % (what, objectname, dl, objectname, dl)
        result = result + "%s " % prefix
        lastdl = dl
      for key in vars.keys():
        line = line.replace("#%s#" % key, vars[key])
      if vars['type'] == 'bool':
        line = line.replace("&","")
        line = line.replace("*(","(",1)
      result = result + line + "\n"
    if lastdl > 0:
      result = result + "}\n\n"
    return result


  def PrintAllVarsDL(self, args):
    "like AllVars, but with surrounding if statements"
    result = ""
    lastdl = 0
    first = True
    args = args.split(":")
    if len(args) < 2:
      print 'Syntax error in PrintAllVarsDL argument'
      return ""
    what = args[0]
    prefix = ""
    if len(args) > 2:
      prefix = args[1]
    args = args[len(args)-1]
    if not self.use_dl:
      return self.AllVars(args)
    for vars in self.variables:
      line = args
      dl   = vars['dl']
      if dl != lastdl:
        result += ";\n"
        if not first:
          result = result + "} // end of detail level %s\n\n" % lastdl
        result = result + "if( "
        for i,detlev in enumerate(dl.split(',')): 
          if i: result += " || "
          result += " ((%s & Ntuple::%s%s) == Ntuple::%s%s) " % (what, objectname, detlev, objectname, detlev)
        result = result + " ) {\n"
        #result = result + "if( (%s & Ntuple::%s%s) == Ntuple::%s%s ) {\n" % (what, objectname, dl, objectname, dl)
        result = result + "%s " % prefix
        first = False
        lastdl = dl
      if vars['type'].find("vector") >= 0:
        result += "  try{"
      for key in vars.keys():
        if (key == "name") and (vars['type'].find("map<") >= 0):
          line = line.replace("#%s#" % key, vars[key],1)
          line = line.replace("rhs.#%s#()" % key, "\" s a map \"" )
        else:
          line = line.replace("#%s#" % key, vars[key])
      #result = result + "\n" + line 
      result = result + line 
      if vars['type'].find("vector") >= 0:
        result += ".at(0);} catch(...){std::cout<<\"except: no element\"<<std::endl;}"
      result+=';\n'
    if lastdl > 0:
      result = result + ";\n}\n\n"
    if lastdl == 0:
      result = result + ";\n"
    return result


  # for stupid bool variables we need two special functions
  def AllNoBools(self, args):
    "replicates a line for all variables but bools"
    result = ""
    for vars in self.variables:
      line = args
      if vars['type'] == 'bool':
        continue
      for key in vars.keys():
        line = line.replace("#%s#" % key, vars[key])
      result = result + line + "\n"
    return result

  
  def AllBools(self, args):
    "replicates a line for all boolean variables"
    result = ""
    for vars in self.variables:
      line = args
      if not vars['type'] == 'bool':
        continue
      for key in vars.keys():
        line = line.replace("#%s#" % key, vars[key])
      result = result + line + "\n"
    return result
  

  def Enums(self, args):
    result = ""
    lastdl = 0
    counter = 0
    dls=[]
    for vars in self.variables: 
      for v in  vars['dl'].split(','):
        dls.append(v)
    for dl in set(dls):
      if dl != lastdl:
        result = result + "    %s%s = %d,\n" % (objectname, dl, pow(2, counter))
        counter += 1
      lastdl = dl
    result = result + "    %sAll = %d,\n" % (objectname, pow(2, counter)-1)
    return result
  

### Configuration
os.environ.keys( )
metadir   = os.environ['SFRAME_DIR'] + '/../NtupleVariables/scripts/Meta/'
targetdir = os.environ['SFRAME_DIR'] + '/../NtupleVariables/'
use_dl    = True

# define additional substitutions here
objects = {
  'Jet'           : {},
  'PuppiJet'      : {'NoBasics': ''},
  'GenJet'        : {'NoBasics': ''},
  'Muon'          : {},
  'Electron'      : {},
  'Tau'           : {},
  # 'Vertex'        : {'NoBasics': ''},
  # 'TrackParticle' : {'NoBasics': ''},
  # 'TruthJet'      : {},
  'GenParticle'   : {},
  # 'Cluster'       : {'NoBasics': ''},
  # 'TrigEFMuon'    : {'NoBasics': ''},
  # 'TrigEFElectron': {'NoBasics': ''},
  'MissingEt'     : {'NoBasics': ''},
  #'BeamSpot': {'NoBasics': ''},
}

### Call code production
if not os.path.exists(targetdir):
  print "Output directory", targetdir, "does not exist"
  sys.exit(1)

for objectname, objectdefs in objects.items():

  templater = Templater(objectname, metadir + 'Variables%s.txt' % objectname)
  templater.AddSubst(objectdefs)
  templater.Use_DL(use_dl)
  
  ### create include/object.h
  templater.CodeIt(metadir + 'IncludeH.txt', targetdir + 'include/%s.h' % objectname)

  ### create src/object.cxx
  templater.CodeIt(metadir + 'SrcCxx.txt',   targetdir + 'src/%s.cxx' % objectname)

  ### create src/objectNtupleobject.h
  templater.CodeIt(metadir + 'IncludeObjectH.txt', targetdir + 'include/%sNtupleObject.h' % objectname)

  ### create src/objectNtupleobject.cxx
  templater.CodeIt(metadir + 'SrcObjectCxx.txt',   targetdir + 'src/%sNtupleObject.cxx' % objectname)

  
