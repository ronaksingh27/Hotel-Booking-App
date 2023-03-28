/*/*Q.What is URN in website ??
A.In the context of websites, "URN" stands for "Uniform Resource Name." A URN is a unique identifier that is used to identify a resource, such as a document or file, on the internet.

Unlike a URL (Uniform Resource Locator), which specifies the location of a resource on the web, a URN is designed to be persistent and can be used to identify a resource even if it has been moved or relocated.

URNs are not commonly used on the web, and URLs are much more prevalent. However, URNs can be useful in some situations, such as when a resource is frequently moved or when it is desirable to have a permanent, unique identifier for a resource that does not depend on its location.*/
---------------------------------------------------------------------------------------------------------------------

/*
Q.What is process.env.MONGO ??
A.process.env.mongo_url is a JavaScript code snippet that is used to access the value of the MONGO_URL environment variable in a Node.js application.
This variable is typically used to store the URL of a MongoDB database, which is used by the application to connect to the database and perform operations on it.  
The value of the MONGO_URL variable can be hard-coded in the application code, or it can be set as an environment variable when running the application. 
By using process.env.mongo_url in the code, the application can access the value of the MONGO_URL variable and use it to establish a connection to the database.
*/

---------------------------------------------------------------------------------------------------------------------

/*
Q.What is mongoose.connection()
A.In the context of Mongoose, mongoose.connection.on is a method that allows you to listen for different events that occur during the connection process to a MongoDB database.

Here is an example code snippet that uses mongoose.connection.on to listen for the 'connected' event:

In this code, mongoose.connect is used to establish a connection to a MongoDB database. Once the connection is established, mongoose.connection is used to get a reference to the connection object.

mongoose.connection.on is then used to register event listeners for different connection events. In this example, we listen for the 'connected' event, the 'error' event, and the 'disconnected' event. When each of these events occurs, the corresponding callback function is executed.
*/

---------------------------------------------------------------------------------------------------------------------

/*
Q.What is the use of app.use(express.json()) ??
A.'app.use(express.json())' is a middleware function in the Express.js framework that is used to parse incoming JSON requests.
When this middleware is used, it adds a new property called "body" to the request object that contains the parsed JSON data. This makes it easy to access the JSON data that is sent from the client in the request body.

Here is an example code snippet that uses app.use(express.json()) to handle incoming JSON data:
*/
//code
const express = require('express');
const app = express();

app.use(express.json());

app.post('/api/user', (req, res) => {
  const user = req.body;
  console.log(user);
  res.send('User created successfully');
});

app.listen(3000, () => {
  console.log('Server started on port 3000');
});
/*
In this example, the app.use(express.json()) middleware function is used to parse incoming JSON requests.

The app.post('/api/user') route handler listens for POST requests to the '/api/user' endpoint. When a request is received, the req.body object is used to access the JSON data sent in the request body.

This makes it easy to create a new user object from the incoming JSON data. Finally, the route handler sends a response back to the client to confirm that the user was created successfully.
*/

---------------------------------------------------------------------------------------------------------------------
/*
Q.What is dotenv.config() ?
A/dotenv.config() is a method from the dotenv module in Node.js that is used to load environment variables from a .env file into the process environment.

The .env file contains key-value pairs of environment variables that are used to configure the application. For example, it can include sensitive information such as API keys, database credentials, and other configuration settings that should not be exposed in the codebase.

Here is an example code snippet that uses dotenv.config() to load environment variables from a .env file:
*/

require('dotenv').config();

const express = require('express');
const app = express();

const port = process.env.PORT || 3000;

app.listen(port, () => {
  console.log(`Server started on port ${port}`);
});
/*
In this example, dotenv.config() is called at the beginning of the file to load environment variables from the .env file.

The process.env.PORT variable is then used to configure the port that the server will listen on. If the PORT variable is not set in the .env file, the default value of 3000 will be used.

Finally, the app.listen() method is used to start the server and listen for incoming HTTP requests on the specified port.

By using dotenv.config(), you can keep sensitive information separate from the codebase and prevent it from being exposed in the version control system.

*/
---------------------------------------------------------------------------------------------------------------------
/*
Q.jwt.sign()
A.JWTs are a type of token that is used to securely transmit information between parties. They consist of three parts: a header, a payload, and a signature. The header contains information about the algorithm used to sign the token, the payload contains the actual data being transmitted, and the signature is used to verify that the token has not been tampered with.
The jwt.sign method takes in three parameters: the payload data to be included in the token, a secret key used to sign the token, and an options object. The options object can be used to specify various settings such as the algorithm used to sign the token and the expiration time of the token.

Here's an example of how to use jwt.sign to create a new JWT in Node

for more info : https://chat.openai.com/chat
*/
const jwt = require('jsonwebtoken');

const payload = { userId: 1234 };
const secretKey = 'mysecretkey';
const options = { expiresIn: '1h' };

const token = jwt.sign(payload, secretKey, options);

console.log(token);
/*
In this example, the jwt.sign method is used to create a new JWT with a payload containing the userId property set to 1234. The secret key used to sign the token is set to mysecretkey, and the expiresIn option is set to 1h, meaning that the token will expire in one hour. Finally, the token is logged to the console.
*/
---------------------------------------------------------------------------------------------------------------------
/*
Q.What is async and await and its uses  ??
A. async is a keyword, async before a function means the function always returns a Promise. Other values are wrapped in a resolved promise automatically.
For more :- https://javascript.info/async-await
*/
---------------------------------------------------------------------------------------------------------------------

/*
Q.Direcotry confusioon
A.  ./ -> current directory
    ../ -> previous directory
*/

