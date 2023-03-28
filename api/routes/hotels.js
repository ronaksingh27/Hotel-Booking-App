import express from "express";
import { appendFile } from "fs";
import Hotel from "../models/Hotel.js"
import createError from "../utils/error.js"
import {createHotel,updateHotel,deleteHotel,getHotel,getAllHotel,countByCity, countByType } from "../controllers/hotel.js"
import { verifyAdmin } from "../utils/verifyToken.js";
 

const router = express.Router();

//create
router.post("/",verifyAdmin, createHotel);

//update
router.put("/:id",verifyAdmin, updateHotel);

//delete
router.delete("/:id",verifyAdmin,deleteHotel)

//get 
router.get("/find/:id",getHotel)//same routes 

//get_all
router.get("/", getAllHotel)

router.get("/countByCity", countByCity)//same routes how will router distnguish between line 21 and 26
router.get("/countByType", countByType)

export default router;