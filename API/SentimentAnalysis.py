import pandas as pd
import sklearn
import numpy as np
from sklearn.feature_extraction.text import CountVectorizer
import csv,time
from pymongo import MongoClient
    
# mongo_uri = 'mongodb+srv://Test:hH5ttQt2sum92Iuv@cluster0.lhjnuxy.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0'

# client = MongoClient(mongo_uri)

# db = client['SentimentAnalysis']
# inputCollection = db['I/O']
# outputCollection = db['Analysis']

# inputData = inputCollection.find({}, {"_id":0})
# outputData = outputCollection.find({}, {"_id":0})

# for document in inputData:
#     print(list(document.values()))

inp = str()

def Analysis(inp):

    if inp:
        test = [inp]

    else:
        exit


    df = pd.read_csv("E:/Documents/Name.csv", header = None)

    x =df.iloc[1:,0]
    y =df.iloc[1:,1]

    x_text = x.values.tolist()
    y_text = y.values.tolist()

    def AI(test,x_text,y_text):
            
        v = CountVectorizer()

        v.fit(x_text)
        vocab = v.get_feature_names_out()
        #print(vocab)

        x_word_matrix = v.transform(x_text)
        x_word_matrix.toarray()

        df = pd.DataFrame(data = x_word_matrix.toarray(),columns = vocab)
        #print(df)

        from sklearn.preprocessing import LabelEncoder
        le = LabelEncoder()
        le.fit(y_text)
        y = le.transform(y_text)

        from sklearn.linear_model import LogisticRegression

        model = LogisticRegression()

        X = x_word_matrix

        clf = model.fit(X,y)

        #test
        test_vector = v.transform(test)
        test_vector.toarray()

        df = pd.DataFrame(data= test_vector.toarray(), columns = vocab)
        #print(df)

        #prediction
        predict = clf.predict(test_vector)
        #print(predict)
        p = le.inverse_transform(predict)
        # print ("Sentiment: ",*p)


        #recur
        new_data = test
        new_labels = p
        
        new_text = [x.lower() for x in x_text]
        
        new = "".join(map(str,new_data))
        
        if new.lower() not in new_text:
            x_text = x_text + new_data
            #print(x)
            #print(y_text,new_labels)
            y_text = np.concatenate((y_text,new_labels),axis=0)

            #print(x_text,y_text)

            df1 = pd.DataFrame(zip(x_text, y_text),  columns = ['Reviews','Sentiment'])
            #print(df)
            df1.to_csv("E:/Documents/Name.csv", index=False)

            time.sleep(0.15)
            #print('Dataset updated')

            # print('Thank You For Your Feedback')
            return p
        else:
            return p
            # print('Thank You For Your Feedback')

    OP = AI(test,x_text,y_text)
    return OP
    