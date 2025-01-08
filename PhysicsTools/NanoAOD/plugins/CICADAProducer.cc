#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/stream/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/L1CaloTrigger/interface/CICADA.h"
#include "DataFormats/L1Trigger/interface/CICADAAnomalyScore.h"

#include <memory>
#include <string>

using namespace std;

class CICADAProducer : public edm::stream::EDProducer<>{
    public:
        explicit CICADAProducer(const edm::ParameterSet&);
        ~CICADAProducer() override;

    private:
        void produce(edm::Event&, const edm::EventSetup&) override;

        edm::EDGetTokenT<l1t::CICADABxCollection> caloLayer1CICADAScoreToken_;
};

CICADAProducer::CICADAProducer(const edm::ParameterSet& iConfig):
    caloLayer1CICADAScoreToken_(consumes<l1t::CICADABxCollection>(iConfig.getParameter<edm::InputTag>("caloLayer1CICADAScore")))
{
    produces<l1t::CICADAAnomalyScore>("CICADAScore");
}

CICADAProducer::~CICADAProducer(){}

void CICADAProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    double scoreVal = (double)iEvent.get(caloLayer1CICADAScoreToken_)[0];
    std::unique_ptr<l1t::CICADAAnomalyScore> CICADAScorePtr = std::make_unique<l1t::CICADAAnomalyScore>();
    l1t::CICADAAnomalyScore CICADAScore(scoreVal);

    *CICADAScorePtr = CICADAScore;
    iEvent.put(std::move(CICADAScorePtr), "CICADAScore");
}

DEFINE_FWK_MODULE(CICADAProducer);
