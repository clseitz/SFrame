path2xml="$SFRAME_DIR/../BatchSubmission/xmls_ReMiniAOD"
path2tmp="$SFRAME_DIR/../AZh/AnalysisTemp"
outDir="$SFRAME_DIR/../AZh/AnalysisOutput"
jobName="AZhAnalysisJob"
cycleName="AZhAnalysis"
outputLevel="WARNING"
nEventsMax=-1
nProcesses=1
nFiles=20
hCPU="06:00:00"
hVMEM="1500M"
postFix = ""


dataSets = []
listDir = "../BatchSubmission/lists_ReMiniAOD"
#for d in ["DYJetsToLL", "DYJetsToLL_Pt-100To250", "DYJetsToLL_Pt-250To400", "DYJetsToLL_Pt-400To650", "DYJetsToLL_Pt-650ToInf", "DYJetsToNuNu_Pt-100To250", "DYJetsToNuNu_Pt-250To400", "DYJetsToNuNu_Pt-400To650", "DYJetsToNuNu_Pt-650ToInf", "WJetsToLNu", "WJetsToLNu_Pt-100To250", "WJetsToLNu_Pt-250To400", "WJetsToLNu_Pt-400To600", "WJetsToLNu_Pt-600ToInf", ]: 
for d in ["DYJetsToLL", "DY1JetsToLL", "DY2JetsToLL", "DY3JetsToLL", "DY4JetsToLL", "DYBBJetsToLL", "DYBJetsToLL", "DYBJetsToLL_Zpt-100to200", "DYBJetsToLL_Zpt-200toInf", "DYBJetsToNuNu_Zpt-40toInf", "DYJetsToLL_HT-100to200", "DYJetsToLL_HT-200to400", "DYJetsToLL_HT-400to600", "DYJetsToLL_HT-600to800", "DYJetsToLL_HT-800to1200", "DYJetsToLL_HT-1200to2500", "DYJetsToLL_HT-2500toInf", "WJetsToLNu", "WJetsToLNu_HT-100To200", "WJetsToLNu_HT-200To400", "WJetsToLNu_HT-400To600", "WJetsToLNu_HT-600To800", "WJetsToLNu_HT-800To1200", "WJetsToLNu_HT-1200To2500", "WJetsToLNu_HT-2500ToInf", "ZJetsToNuNu_HT-100To200", "ZJetsToNuNu_HT-200To400", "ZJetsToNuNu_HT-400To600", "ZJetsToNuNu_HT-600To800", "ZJetsToNuNu_HT-800To1200", "ZJetsToNuNu_HT-1200To2500", "ZJetsToNuNu_HT-2500ToInf", "WJetsToQQ_HT-600ToInf", "WWTo4Q", "WWTo2L2Nu", "WWTo1L1Nu2Q", "WZTo1L1Nu2Q", "WZTo2L2Q", "WZTo2Q2Nu", "ZZTo2L2Q", "ZZTo2L2Nu", "ZZTo2Q2Nu", "ZZTo4Q", "ZZTo4L", "ZHToLLBB", "ZHToNuNuBB", "ZHToQQBB", "WHToLNuBB", "GluGluHToBB"]:
#["WWTo1L1Nu2Q", "WZTo1L1Nu2Q", "ZZTo2L2Q", "ZZTo2Q2Nu", "ZZTo4Q", "ZZTo4L", "ZHToLLBB", "ZHToNuNuBB", "ZHToQQBB", "WHToLNuBB", "GluGluHToBB", "WJetsToQQ_HT-600ToInf", "WJetsToLNu_HT-100To200", "WJetsToLNu_HT-200To400", "WJetsToLNu_HT-400To600", "WJetsToLNu_HT-600To800", "WJetsToLNu_HT-800To1200", "WJetsToLNu_HT-1200To2500", "WJetsToLNu_HT-2500ToInf", "DYJetsToLL_HT-100to200", "DYJetsToLL_HT-200to400", "DYJetsToLL_HT-400to600", "DYJetsToLL_HT-600to800", "DYJetsToLL_HT-800to1200", "DYJetsToLL_HT-1200to2500", "DYJetsToLL_HT-2500toInf", "ZJetsToNuNu_HT-100To200", "ZJetsToNuNu_HT-200To400", "ZJetsToNuNu_HT-400To600", "ZJetsToNuNu_HT-600To800", "ZJetsToNuNu_HT-800To1200", "ZJetsToNuNu_HT-1200To2500", "ZJetsToNuNu_HT-2500ToInf", "DYJetsToLL", "WJetsToLNu"]: #"WWTo4Q", "WZTo2L2Q", "ZJetsToQQ_HT-600ToInf"
    dataSets.append([d, open(listDir+"/"+d+".txt").read().splitlines()])


userItems = [
    ["IsData", "false"],
    ["IsSignal", "false"],
]

jobOptionsFile2=open("AnalysisOptions.py", 'r')
command2=""
for i in [o for o in jobOptionsFile2.readlines()]:
  if ("#E" + "nd") in i : break
  command2+=i
jobOptionsFile2.close()
exec command2
userItems += AddUserItems


inputTrees=["ntuplizer/tree"]
outputTrees=["tree"]
