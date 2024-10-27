import pandas as pd
import sklearn
import numpy as np
from sklearn.feature_extraction.text import CountVectorizer
import csv,time

inp = str(input("Please enter your feedback\n"))
test = [inp]
    
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
    print ("Sentiment: ",*p)

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
        print('Thank You For Your Feedback')
    else:
        print('Thank You For Your Feedback')

        
AI(test,x_text,y_text)
