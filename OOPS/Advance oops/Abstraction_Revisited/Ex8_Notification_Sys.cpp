// Exercise 8: Notification System
// Problem: Create a notification system that can send messages through different channels.

// Requirements:

// Abstract class Notification with:
// send() (pure virtual)
// setMessage() (concrete)
// getType() (pure virtual)

// Implement classes:

// EmailNotification
// SMSNotification
// PushNotification

// Create a NotificationManager that can send batches of notifications
// Add a method to send urgent notifications (all caps) vs normal notifications
#include <bits/stdc++.h>
using namespace std;

class Notification
{
protected:
  string message;

public:
  void setMessage(const string &mess)
  {
    message = mess;
  }
  virtual void send() = 0;
  virtual string getType() const = 0;

  virtual ~Notification() = default;
};

class EmailNotification : public Notification
{
public:
  void send() override
  {
    cout << "[Email] Sending: " << message << endl;
  }
  string getType() const override
  {
    return "Email";
  }
};
class SMSNotification : public Notification
{
  public: 
    void send() override{
      cout<<"[SMS] Sending: "<<message<<endl;
    }
    string getType() const override{
      return "SMS";
    }
};
class PushNotification : public Notification
{
  public: 
    void send() override{
      cout<<"[PUSH] Sending: "<<message<<endl;
    }
    string getType() const override{
      return "PUSH";
    }
};

enum class NotificationType
{
  EmailNotification,
  SMSNotification,
  PushNotification
};

class NotificationManager
{
public:
  std::unique_ptr<Notification> createNotification(NotificationType type)
  {
    switch(type){
      case NotificationType::EmailNotification:
        return make_unique<EmailNotification>();
      case NotificationType::SMSNotification:
        return make_unique<SMSNotification>();
      case NotificationType::PushNotification:
        return make_unique<PushNotification>();
      default:
        return nullptr;
    }
  }

  void sendNotification(Notification& notification,const string& msg){
    notification.setMessage(msg);
    notification.send();
  }
  void sendUrgentNotification(Notification& notification,const string& msg){
    string upper = msg;
    transform(upper.begin(),upper.end(),upper.begin(),[](unsigned char c){ return toupper(c); });
    notification.setMessage(upper);
    notification.send();
  }

  void sendBatch(const vector<unique_ptr<Notification>>& notifications,const string& msg, bool urgent = false){
    for(auto& n : notifications){
      if(urgent){
        sendUrgentNotification(*n,msg);
      }
      else{
        sendNotification(*n,msg);
      }
    }
  }
};


int main(){
  NotificationManager manager;
  vector<unique_ptr<Notification>> notifications;
  notifications.push_back(manager.createNotification(NotificationType::EmailNotification));
  notifications.push_back(manager.createNotification(NotificationType::SMSNotification));
  notifications.push_back(manager.createNotification(NotificationType::PushNotification));

  cout<<"Normal Message----------"<<endl;
  manager.sendBatch(notifications,"Good Morning");
  cout<<endl;

  cout<<"Urgent Message--------"<<endl;
  manager.sendBatch(notifications,"Good Morning",true);
  return 0;
}
