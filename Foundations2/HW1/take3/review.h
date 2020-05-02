#include <iostream>
#include <fstream>
using namespace std;

class Review
{
public:
  Review();
  Review(const Review & review);
  ~Review();

  //getters
  string getReviewerName()const;
  string getRestaurantName()const;
  string getVisitDate()const;
  string getComments()const;
  int getFoodRating()const;
  int getServiceRating()const;
  int getValueRating()const;
  int getAtmosphereRating()const;
  int getOverallRating()const;

  //setters
  void setReviewerName(const string & reviewerName);
  void setRestaurantName(const string & restaurantName);
  void setVisitDate(const string & visitDate);
  void setComments(const string & comments);
  void setFoodRating(const int & foodRating);
  void setServiceRating(const int & serviceRating);
  void setValueRating(const int & valueRating);
  void setAtmosphereRating(const int & atmosphereRating);
  void setOverallRating(const int & overallRating);

  //other methods
  int calculateOverallRating();
  void insertReview(Review review[]);
  void searchReview(const Review review[],const int count);

  //print
  void print()const;

private:
  string mReviewerName;
  string mRestaurantName;
  string mVisitDate;
  string mComments;
  int mFoodRating;
  int mServiceRating;
  int mValueRating;
  int mAtmosphereRating;
  int mOverallRating;

};
