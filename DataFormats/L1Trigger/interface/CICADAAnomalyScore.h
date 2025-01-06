#ifndef DataFormats_L1Trigger_CICADAAnomalyScore_h
#define DataFormats_L1Trigger_CICADAAnomalyScore_h

#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/L1Trigger/interface/L1Candidate.h"
#include "DataFormats/L1Trigger/interface/BXVector.h"
#include "DataFormats/L1Trigger/interface/L1TObjComparison.h"

namespace l1t {

  class CICADAAnomalyScore;
  typedef BXVector<CICADAAnomalyScore> CICADAAnomalyScoreBxCollection;
  typedef edm::Ref<CICADAAnomalyScoreBxCollection> CICADAAnomalyScoreRef;
  typedef edm::RefVector<CICADAAnomalyScoreBxCollection> CICADAAnomalyScoreRefVector;
  typedef std::vector<CICADAAnomalyScoreRef> CICADAAnomalyScoreVectorRef;

  typedef ObjectRefBxCollection<CICADAAnomalyScore> CICADAAnomalyScoreRefBxCollection;
  typedef ObjectRefPair<CICADAAnomalyScore> CICADAAnomalyScoreRefPair;
  typedef ObjectRefPairBxCollection<CICADAAnomalyScore> CICADAAnomalyScoreRefPairBxCollection;

  class CICADAAnomalyScore : public L1Candidate {
  public:
    //CICADAAnomalyScore();

    CICADAAnomalyScore(double score = 0);

    ~CICADAAnomalyScore() override;

    // set values
    inline void setScore(int score_val) { score_ = score_val; };

    // methods to retrieve values
    inline int score() const { return score_; };

  private:
    int score_;
  };

}  // namespace l1t

#endif
