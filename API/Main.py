from fastapi import FastAPI, Request, UploadFile, File, HTTPException
from fastapi.templating import Jinja2Templates
from fastapi.responses import JSONResponse
from fastapi.staticfiles import StaticFiles
from fastapi.middleware.cors import CORSMiddleware
import uvicorn
from motor.motor_asyncio import AsyncIOMotorClient
import openai
import os
import io
import base64
import SentimentAnalysis



app = FastAPI()

templates = Jinja2Templates(directory="templates")
app.mount("/static", StaticFiles(directory="static"), name="static")

@app.get("/")
async def get(request: Request):
    return templates.TemplateResponse("Home.html", {"request": request})

@app.post("/chat")
async def chat(request: Request):
    form_data = await request.json()
    user_message = form_data.get("message")
    # SentimentAnalysis.inp = user_message

    # Dummy chatbot response (replace with actual logic or API call)
    bot_response = f"Sentiment: {SentimentAnalysis.Analysis(user_message)}\nThank You For feedback"

    return JSONResponse({"response": bot_response})


@app.post("/upload-image")
async def upload_image(file: UploadFile = File(...)):
    contents = await file.read()

    # Convert to base64 to store in MongoDB
    image_base64 = base64.b64encode(contents).decode('utf-8')

    # Optionally, you can process the image here (e.g., diagnose using ML model)

    # Save to MongoDB
    # await db.images.insert_one({"filename": file.filename, "image_base64": image_base64})

    print(f"Recieved File: {file.filename}")

    return {"filename": file.filename}



# templates = Jinja2Templates(directory="templates")
# general_pages_router = APIRouter()


# app = FastAPI()
# @app.get("/")
# def home(request: Request):
# 	return templates.TemplateResponse("Home.html",context={"request":request})


# @app.get("/Ayan")
# async def root():
#     return f"Hi My name is Ayan, please check my api"

if __name__ == "__main__" :
    uvicorn.run(app)