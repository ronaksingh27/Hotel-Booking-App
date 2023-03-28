import express from 'express'
import mongoose from 'mongoose';
import dotenv from "dotenv"
import authRoute from './routes/auth.js'
import hotelsRoute from './routes/hotels.js'
import roomsRoute from './routes/rooms.js'
import usersRoute from './routes/users.js'
import cookieParser from 'cookie-parser'


const app = express();
dotenv.config();//✅


/*
Q.How is the order of execution of the index.js file ??🚩
O/P -> connected to port 2708
       mongoose is connected for now
       connected to mongo db

*/
//✅
const connect = async ()=>{

    try{
        await mongoose.connect(process.env.MONGO);
        console.log("connected to mongo db");
    } catch(error){
        throw error;
    }
};

//✅
mongoose.connection.on("disconnected",()=>{
    console.log("mongoose is disconnected for now")
})

mongoose.connection.on("error",(error)=>{
    console.log("Erros is ",error);
})
mongoose.connection.on("connected",()=>{
    console.log("mongoose is connected for now");
})


//middlewares


app.use(cookieParser())
app.use(express.json());//✅

app.use("/api/auth",authRoute);
app.use("/api/hotels",hotelsRoute);
app.use("/api/rooms",roomsRoute);
app.use("/api/users",usersRoute);

//error handling middleware ✅
app.use((err,req,res,next)=>{
    const errorStatus = err.status || 500;
    const errorMessage = err.message || "something went wrong :";
    return res.status(errorStatus).json({
        success: false,
        status : errorStatus,
        message: errorMessage,
        stack: err.stack
    });


})
    


app.listen(2708,()=>{
    connect();//🚩
    console.log("connected to port 2708")
})