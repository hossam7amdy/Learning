/// Homework 8: System Design
/*
● In Medal of Honor game, there are millions of Online players
    ○ Sometimes there is some message from the game to the players
● There are 2 ways to deliver the message:
    ○ Each app periodically contacts the server to see if there are new notifications or not
■ Then Game site provide an API to be contacted through it
■ Each mobile/desktop/tablet send/receive request/response
    ○ When user opens the application, a registration message is sent to the game
■ Whenever server has a new message, it iterates on whoever registered and send msg
■ We need to handle different types of devices
    ○ Discuss the 2 options. Any notes on their implementations.
*/

/// Answer
/*
- Scalability is a critical key to the success of the business. Let's think about it for the following 2 choices
- Assume we have 10 Million mobile users, say of 15 different types of mobiles


Choice 1: Each app periodically contacts the server to see if there are new notifications or not
- As mobiles are creating the requests, this means the server is receiving periodically millions of requests
- 2 critical problems here
- The server will be very slow to handle "concurrent requests" of such size
- Most of the time there won't be messages to notify


Choice 2: When a user opens his mobile game, he sends to the Game to register for messages to get notifications
- The server provides an API for apps to register or de-register
- When there is a message, the server loops on them and just notify
- Each device type might need special code to send notifications




Implementation:
Choice 1:
You need a thread per mobile app that wakes up say each 1 minute, then send a request for the Game API


Choice 2:
You need to give API to get register/de-register requests
You need to handle each device type separately
You need with every message to iterate on objects of each device type to send a request
    E.g. vector<Mobile> mobiles;   vector<Tablets> tablets;   vector<Desktop> desktops;
    
    It is a bit annoying to do such duplication in efforts
    With polymorphism, we see how this can be done better
    With the Observer design pattern, we see how such problem is common
*/
