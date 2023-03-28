import User from "../models/User.js"
import bcrypt from 'bcrypt';
import createError from "../utils/error.js";
import  Jwt from "jsonwebtoken";

export const register = async (req,res,next)=>{
    try{

        const saltRounds = 10;
        const salt = bcrypt.genSaltSync(saltRounds);
        const hash = bcrypt.hashSync(req.body.password, salt);

        const newUser = new User({
        username:req.body.username,
        email:req.body.email,
        password:req.body.password,
        isAdmin:req.body.isAdmin
       })

       console.log("user is being created")
       await newUser.save()//save is a fucntion/method of mongoose
       res.status(200).send("User has been created");
    }catch(err){
        next(err);
    }
}

export const login = async (req,res,next)=>{
    try{
        console.log("login invoked");

        //user
        const user = await User.findOne({username:req.body.username})//await tha idhar jisne utna tien lagaya,abhi ke liye jaane de

        if(!user){
            console.log("user not found");
            return next(createError(404,"user not found"));
            
        } 
        if(user){
            console.log("user found");
            
        }

        // const isPasswordCorrect = await bcrypt.compare(req.body.password,user._doc.password);

        
        // if(!isPasswordCorrect){
        //     console.log("password not found");
        //     return next(createError(400,"Wrong password for username"));
        // }

        const token = Jwt.sign(
            {id:user._id,isAdmin:user.isAdmin},
            process.env.JWT
        );
        


        const {password,isAdmin,...otherDetails} = user._doc;
        res
        .cookie("access_token",token,{
            httpOnly:true,
        })
        .status(200)
        .json({...otherDetails});

       
    }catch(err){
        next(err);
    }
}



