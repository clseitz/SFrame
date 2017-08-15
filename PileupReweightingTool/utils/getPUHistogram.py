#! /usr/bin/env python

import os
from array import array
from ROOT import gStyle, TFile, TH1F, TCanvas, TLegend, ROOT, gROOT

gStyle.SetOptStat(0)

import optparse
usage = "usage: %prog [options]"
parser = optparse.OptionParser(usage)
#parser.add_option("-d", "--dataFile", action="store", type="string", default=False, dest="dataFileName")
#parser.add_option("-m", "--mcFile", action="store", type="string", default=False, dest="mcFileName")
#parser.add_option("-r", "--mcReweightedFile", action="store", type="string", default=False, dest="mcReweightedFileName")
#parser.add_option("-p", "--plot", action="store_true", default=False, dest="doPlot")
parser.add_option("-s", "--save", action="store_true", default=False, dest="save")
parser.add_option("-b", "--batch", action="store_true", default=False, dest="batch")
(options, args) = parser.parse_args()
if options.batch: gROOT.SetBatch(True)

#scp lxplus.cern.ch:/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/PileUp/pileup_latest.txt ../../GoodRunsLists/JSON/
#pileupCalc.py -i ../../GoodRunsLists/JSON/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt  --inputLumiJSON ../../GoodRunsLists/JSON/pileup_latest.txt  --calcMode true --minBiasXsec 69200 --maxPileupBin 75 --numPileupBins 75 ../histograms/Moriond17_69200.root
#pileupCalc.py -i ../../GoodRunsLists/JSON/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt  --inputLumiJSON ../../GoodRunsLists/JSON/pileup_latest.txt  --calcMode true --minBiasXsec 66156 --maxPileupBin 75 --numPileupBins 75 ../histograms/Moriond17_66156.root
#pileupCalc.py -i ../../GoodRunsLists/JSON/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt  --inputLumiJSON ../../GoodRunsLists/JSON/pileup_latest.txt  --calcMode true --minBiasXsec 72383 --maxPileupBin 75 --numPileupBins 75 ../histograms/Moriond17_72383.root

# https://raw.githubusercontent.com/cms-sw/cmssw/CMSSW_7_4_X/SimGeneral/MixingModule/python/mix_2015_25ns_Startup_PoissonOOTPU_cfi.py
#probValue = [4.8551E-07, 1.74806E-06, 3.30868E-06, 1.62972E-05, 4.95667E-05, 0.000606966, 0.003307249, 0.010340741, 0.022852296, 0.041948781, 0.058609363, 0.067475755, 0.072817826, 0.075931405, 0.076782504, 0.076202319, 0.074502547, 0.072355135, 0.069642102, 0.064920999, 0.05725576, 0.047289348, 0.036528446, 0.026376131, 0.017806872, 0.011249422, 0.006643385, 0.003662904, 0.001899681, 0.00095614, 0.00050028, 0.000297353, 0.000208717, 0.000165856, 0.000139974, 0.000120481, 0.000103826, 8.88868E-05, 7.53323E-05, 6.30863E-05, 5.21356E-05, 4.24754E-05, 3.40876E-05, 2.69282E-05, 2.09267E-05, 1.5989E-05, 4.8551E-06, 2.42755E-06, 4.8551E-07, 2.42755E-07, 1.21378E-07, 4.8551E-08]

# https://github.com/cms-sw/cmssw/blob/CMSSW_8_1_X/SimGeneral/MixingModule/python/mix_2016_25ns_SpringMC_PUScenarioV1_PoissonOOTPU_cfi.py
#probValue = [0.000829312873542, 0.00124276120498, 0.00339329181587, 0.00408224735376, 0.00383036590008, 0.00659159288946, 0.00816022734493, 0.00943640833116, 0.0137777376066, 0.017059392038, 0.0213193035468, 0.0247343174676, 0.0280848773878, 0.0323308476564, 0.0370394341409, 0.0456917721191, 0.0558762890594, 0.0576956187107, 0.0625325287017, 0.0591603758776, 0.0656650815128, 0.0678329011676, 0.0625142146389, 0.0548068448797, 0.0503893295063, 0.040209818868, 0.0374446988111, 0.0299661572042, 0.0272024759921, 0.0219328403791, 0.0179586571619, 0.0142926728247, 0.00839941654725, 0.00522366397213, 0.00224457976761, 0.000779274977993, 0.000197066585944, 7.16031761328e-05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]

# https://github.com/cms-sw/cmssw/blob/CMSSW_8_1_X/SimGeneral/MixingModule/python/mix_2016_25ns_Moriond17MC_PoissonOOTPU_cfi.py
probValue = [1.78653e-05 ,2.56602e-05 ,5.27857e-05 ,8.88954e-05 ,0.000109362 ,0.000140973 ,0.000240998 ,0.00071209 ,0.00130121 ,0.00245255 ,0.00502589 ,0.00919534 ,0.0146697 ,0.0204126 ,0.0267586 ,0.0337697 ,0.0401478 ,0.0450159 ,0.0490577 ,0.0524855 ,0.0548159 ,0.0559937 ,0.0554468 ,0.0537687 ,0.0512055 ,0.0476713 ,0.0435312 ,0.0393107 ,0.0349812 ,0.0307413 ,0.0272425 ,0.0237115 ,0.0208329 ,0.0182459 ,0.0160712 ,0.0142498 ,0.012804 ,0.011571 ,0.010547 ,0.00959489 ,0.00891718 ,0.00829292 ,0.0076195 ,0.0069806 ,0.0062025 ,0.00546581 ,0.00484127 ,0.00407168 ,0.00337681 ,0.00269893 ,0.00212473 ,0.00160208 ,0.00117884 ,0.000859662 ,0.000569085 ,0.000365431 ,0.000243565 ,0.00015688 ,9.88128e-05 ,6.53783e-05 ,3.73924e-05 ,2.61382e-05 ,2.0307e-05 ,1.73032e-05 ,1.435e-05 ,1.36486e-05 ,1.35555e-05 ,1.37491e-05 ,1.34255e-05 ,1.33987e-05 ,1.34061e-05 ,1.34211e-05 ,1.34177e-05 ,1.32959e-05 ,1.33287e-05]


mc = TH1F("pileup", "True nPV distribution", len(probValue), 0, len(probValue))
mc.Sumw2()
for i in range(len(probValue)): mc.SetBinContent(i+1, probValue[i])
mc.SetLineWidth(3)
mc.SetLineColor(1)
mc.SetLineStyle(2)
mc.Scale(1./mc.Integral())

if options.save:
    outFile = TFile("../histograms/Moriond17_MC.root", "RECREATE")
    outFile.cd()
    mc.Write()
    outFile.Close()
    print "Histograms written to ../data/Moriond17_MC.root file"
    exit()
   
puFile = TFile("../histograms/Moriond17_69200.root", "READ")
data = puFile.Get("pileup")
data.SetLineWidth(3)
data.SetLineColor(1)
data.Scale(1./data.Integral())

puUpFile = TFile("../histograms/Moriond17_72383.root", "READ")
dataUp = puUpFile.Get("pileup")
dataUp.SetLineWidth(3)
dataUp.SetLineColor(634)
dataUp.Scale(1./dataUp.Integral())

puDownFile = TFile("../histograms/Moriond17_66156.root", "READ")
dataDown = puDownFile.Get("pileup")
dataDown.SetLineWidth(3)
dataDown.SetLineColor(598)
dataDown.Scale(1./dataDown.Integral())

ratio = data.Clone("ratio")
ratioUp = dataUp.Clone("ratioUp")
ratioDown = dataDown.Clone("ratioDown")

ratio.Divide(mc)
ratioUp.Divide(mc)
ratioDown.Divide(mc)

#outFile = TFile("../data/PU.root", "RECREATE")
#outFile.cd()
#mc.Write()
#data.Write()
#dataUp.Write()
#dataDown.Write()
#ratio.Write()
#ratioUp.Write()
#ratioDown.Write()
#outFile.Close()
#print "Histograms written to ../data/PU.root file"

leg = TLegend(0.65, 0.7, 0.98, 0.9)
leg.SetBorderSize(0)
leg.SetFillStyle(0) #1001
leg.SetFillColor(0)
leg.SetHeader("Pile Up reweighting")
leg.AddEntry(dataUp, "Up", "pl")
leg.AddEntry(data, "Central", "pl")
leg.AddEntry(dataDown, "Down", "pl")
leg.AddEntry(mc, "Moriond17 MC", "pl")

c1 = TCanvas("c1", "PileUp reweighting", 800, 800)
c1.cd()
c1.GetPad(0).SetTopMargin(0.06)
c1.GetPad(0).SetRightMargin(0.05)
c1.GetPad(0).SetTicks(1, 1)
dataDown.SetTitle(";number of true interactions")
#dataDown.GetXaxis().SetRangeUser(0., 30)
dataDown.Draw("HIST")
dataUp.Draw("SAME, HIST")
data.Draw("SAME, HIST")
mc.Draw("SAME, L")
leg.Draw()
c1.Print("PU.pdf")
c1.Print("PU.png")

