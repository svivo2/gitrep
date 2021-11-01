#include "review.h"

Review::Review()
{
  mReviewerName = "";
  mRestaurantName = "";
  mVisitDate = "";
  mComments = "";
  mFoodRating = 0;
  mServiceRating = 0;
  mValueRating = 0;
  mAtmosphereRating = 0;
  mOverallRating = -1;
}
Review::Review(const Review & review)
{
  mReviewerName = review.mReviewerName;
  mRestaurantName = review.mRestaurantName;
  mVisitDate = review.mVisitDate;
  mComments = review.mComments;
  mFoodRating = review.mFoodRating;
  mServiceRating = review.mServiceRating;
  mValueRating = review.mValueRating;
  mAtmosphereRating = review.mAtmosphereRating;
  mOverallRating = review.mOverallRating;
}

Review::~Review()
{
}

//getters
string Review::getReviewerName() const
{
  return mReviewerName;
}
string Review::getRestaurantName() const
{
  return mRestaurantName;
}
string Review::getVisitDate() const
{
  return mVisitDate;
}
string Review::getComments() const
{
  return mComments;
}
int Review::getFoodRating() const
{
  return mFoodRating;
}
int Review::getServiceRating() const
{
  return mServiceRating;
}
int Review::getValueRating() const
{
  return mValueRating;
}
int Review::getAtmosphereRating() const
{
  return mAtmosphereRating;
}
int Review::getOverallRating() const
{
  return mOverallRating;
}

//setters
void Review::setReviewerName(const string & reviewerName)
{
  mReviewerName = reviewerName;
}
void Review::setRestaurantName(const string & restaurantName)
{
  mRestaurantName = restaurantName;
}
void Review::setVisitDate(const string & visitDate)
{
  mVisitDate = visitDate;
}
void Review::setComments(const string & comments)
{
  mComments = comments;
}
void Review::setFoodRating(const int & foodRating)
{
  mFoodRating = foodRating;
}
void Review::setServiceRating(const int & serviceRating)
{
  mServiceRating = serviceRating;
}
void Review::setValueRating(const int & valueRating)
{
  mValueRating = valueRating;
}
void Review::setAtmosphereRating(const int & atmosphereRating)
{
  mAtmosphereRating = atmosphereRating;
}
void Review::setOverallRating(const int & overallRating)
{
  mOverallRating = overallRating;
}

int Review::calculateOverallRating()
{
  return ((mFoodRating + mValueRating + mServiceRating + mAtmosphereRating + 2)/4);
}

void Review::insertReview(Review review[])
{
  string tmpString = "";
  Review tmpReview;
  int tmpInt = 0;

  cout << "\nPlease enter your first name followed by your last name sepatated by a single space: ";

  getline(cin, tmpString);
  getline(cin, tmpString);
  tmpReview.setReviewerName(tmpString);

  cout << "\nPlease enter the restaurant name: ";

  getline(cin, tmpString);
  tmpReview.setRestaurantName(tmpString);

  cout << "\nPlease enter date of visit: ";

  getline(cin, tmpString);
  tmpReview.setVisitDate(tmpString);

  while (tmpInt < 1 || tmpInt > 5)
  {
    cout << "\nPlease rate the food from 1 - 5: ";
    cin >> tmpInt;
  }

  tmpReview.setFoodRating(tmpInt);

  tmpInt = 0;
  while (tmpInt < 1 || tmpInt > 5)
  {
    cout << "\nPlease rate the sevice from 1 - 5: ";
    cin >> tmpInt;
  }

  tmpReview.setServiceRating(tmpInt);

  tmpInt = 0;
  while (tmpInt < 1 || tmpInt > 5)
  {
    cout << "\nPlease rate the value from 1 - 5: ";
    cin >> tmpInt;
  }

  tmpReview.setValueRating(tmpInt);

  tmpInt = 0;
  while (tmpInt < 1 || tmpInt > 5)
  {
    cout << "\nPlease rate the atmosphere from 1 - 5: ";
    cin >> tmpInt;
  }

  tmpReview.setAtmosphereRating(tmpInt);

  tmpReview.setOverallRating(tmpReview.calculateOverallRating());

  cout << "\nPlease enter any comments you would like to add: ";

  getline(cin, tmpString);
  getline(cin, tmpString);

  tmpReview.setComments(tmpString);

  tmpReview.print();

  int i = 0;
  while(review[i].getOverallRating() != -1)
    i++;

  review[i].setReviewerName(tmpReview.getReviewerName());
  review[i].setRestaurantName(tmpReview.getRestaurantName());
  review[i].setVisitDate(tmpReview.getVisitDate());
  review[i].setComments(tmpReview.getComments());
  review[i].setFoodRating(tmpReview.getFoodRating());
  review[i].setServiceRating(tmpReview.getServiceRating());
  review[i].setValueRating(tmpReview.getValueRating());
  review[i].setAtmosphereRating(tmpReview.getAtmosphereRating());
  review[i].setOverallRating(tmpReview.getOverallRating());

}

void Review::searchReview(const Review review[], const int count)
{
  // Prompt user for input
  string choice = "";
  while ((choice != "restaurant") && (choice != "reviewer"))
  {
    cout << "Enter type of search (restaurant or reviewer): ";
    cin >> choice;
  }

  cout << "Enter search string: ";
  string search;
  getline(cin, search);
  getline(cin, search);

  // Search book array for matching data
  for (int i = 0; i < count; i++)
  {
    if ((choice == "restaurant") && (search == review[i].getRestaurantName()))
      review[i].print();
    if ((choice == "reviewer") && (search == review[i].getReviewerName()))
      review[i].print();
  }
  return;
}

//print
void Review::print()const
{
  cout << "Reviewer name: "<< getReviewerName() << endl;
  cout << "Resturant name: "<< getRestaurantName() << endl;
  cout << "Date of Visit: " << getVisitDate() << endl;
  cout << "Food Rating: " << getFoodRating() << endl;
  cout << "Service Rating: " << getServiceRating() << endl;
  cout << "Value Rating: " << getValueRating() << endl;
  cout << "Atmophere Rating: " << getAtmosphereRating() << endl;
  cout << "Overall Rating: " << getOverallRating() << endl;
  cout << "Comments: " << getComments() << endl;
}
