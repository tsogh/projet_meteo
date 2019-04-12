import os
import binascii
from flask import Flask, request, jsonify
import sqlite3 as lite
import sys
import json
from flask.ext.cors import CORS

app = Flask(__name__)
cors = CORS(app, resources={r"/users": {"origins": "*"}})

@app.route("/")
def status():
    print(request.args.get('msisdn'))
    con = lite.connect('cars.db')
    with con:
        cur=con.cursor()
        cur.execute('SELECT SQLITE_VERSION()')
        data=cur.fetchone()
    con.close()
    return "SQLite version: %s" % data

##@app.route("/dump")
##def dump():
##    con = lite.connect('cars.db')    
##    with con:
##        con.row_factory = lite.Row
##        cur = con.cursor() 
##        cur.execute("SELECT * FROM Cars")
##        rows = cur.fetchall()
##        print rows
##        print dict(rows[0])
##        list=json.dumps( [dict(ix) for ix in rows] )
##    con.close()    
##    return list

@app.route("/cars/<id>", methods=['GET','POST'])
def cars(id):
    if request.method == 'GET':
        try:
            con = lite.connect('cars.db')
            with con:
                cur.execute('SELECT * FROM Cars WHERE Id=' + id)
                l=cur.fetchone()
            con.close()
     
        except lite.Error, e:
            return e.args[0],404
    
        if l==None:
            return "",404
        else:
            return '{"Id":"%s", "Name":"%s", "Price":"%s"}'%(l)
    else:
        try:
            con = lite.connect('cars.db')
            with con:
                body=request.form
                p=(id,body['Name'],body['Price'])
		print body['Price'];
                #cur.execute("INSERT INTO Cars VALUES(?,?,?);", (id,body['Name'],body['Price']))
		cur.execute("INSERT INTO Cars VALUES(?,?,?);",p)
            con.close()
            return '{"Id":"%s", "Name":"%s", "Price":"%s"}'%(p),201
        except lite.Error, e:
            return e.args[0],404

@app.route('/cars/user',methods=['GET'])
def numUsers():
	i=0
	conn=lite.connect('cars.db')
	cursor=conn.cursor()
	cursor.execute('SELECT * FROM Users')
	for u in cursor:
		i=i+1
	conn.close()
	return '%s'%(i)

@app.route('/cars/liste/<id>',methods=['GET'])
def liste(id):
	liste_c=[]
	conn=lite.connect('cars.db')
	cursor=conn.cursor()
	cursor.execute('SELECT * FROM Users where Id='+id)
	l=cursor.fetchone()
	conn.close()
	if l==None:
		print "fin"
	#return json.dumps(liste_c)
	return '%s : %s %s'%(l)

@app.route('/users',methods=['PUT'])
def maj():
	name=request.form['Name']
	password=request.form['Password']
	#conn=lite.connect('cars.db')
        cur=con.cursor()
	cur.execute("UPDATE Users set Password = (?) where Name = (?)",(password,name))
	con.commit()
	
	return "",200

@app.route("/users/<id>", methods=['GET'])
def users(id):
        try:
            con = lite.connect('cars.db')
            with con:
                cur.execute('SELECT * FROM Users WHERE Id=' + id)
                l=cur.fetchone()
            con.close()
        except lite.Error, e:
            return e.args[0],404

        if l==None:
            return "",404
        else:
            return '{"Id":"%s", "Name ":"%s", "Password":"%s"}'%(l)

@app.route("/refresh", methods=['GET'])
def refresh():
        cur=con.cursor()
        cur.execute("DROP TABLE IF EXISTS Users")
        cur.execute("CREATE TABLE Users(Id INT, Name TEXT, Password TEXT)")
        cur.execute("INSERT INTO Users VALUES(1,'admin','admin')")
        cur.execute("INSERT INTO Users VALUES(2,'toto','mypass')")
        cur.execute("INSERT INTO Users VALUES(3,'user','pass')")

        cur.execute("DROP TABLE IF EXISTS Cars")
        cur.execute("CREATE TABLE Cars(Id INT, Name TEXT, Price INT)")
        cur.execute("INSERT INTO Cars VALUES(1,'Audi',52642)")
        cur.execute("INSERT INTO Cars VALUES(2,'Mercedes',57127)")
        cur.execute("INSERT INTO Cars VALUES(3,'Skoda',9000)")
        cur.execute("INSERT INTO Cars VALUES(4,'Volvo',29000)")
        cur.execute("INSERT INTO Cars VALUES(5,'Bentley',350000)")
        cur.execute("INSERT INTO Cars VALUES(6,'Citroen',21000)")
        cur.execute("INSERT INTO Cars VALUES(7,'Hummer',41400)")
        cur.execute("INSERT INTO Cars VALUES(8,'Volkswagen',21600)")

	return "",200

if __name__ == "__main__":
    app.debug = True
    
# Fabrique la base
    con=lite.connect('cars.db',check_same_thread=False)
    with con:
        cur=con.cursor()
        cur.execute("DROP TABLE IF EXISTS Users")
        cur.execute("CREATE TABLE Users(Id INT, Name TEXT, Password TEXT)")
        cur.execute("INSERT INTO Users VALUES(1,'admin','admin')")
        cur.execute("INSERT INTO Users VALUES(2,'toto','mypass')")
        cur.execute("INSERT INTO Users VALUES(3,'user','pass')")

        cur.execute("DROP TABLE IF EXISTS Cars")
        cur.execute("CREATE TABLE Cars(Id INT, Name TEXT, Price INT)")
        cur.execute("INSERT INTO Cars VALUES(1,'Audi',52642)")
        cur.execute("INSERT INTO Cars VALUES(2,'Mercedes',57127)")
        cur.execute("INSERT INTO Cars VALUES(3,'Skoda',9000)")
        cur.execute("INSERT INTO Cars VALUES(4,'Volvo',29000)")
        cur.execute("INSERT INTO Cars VALUES(5,'Bentley',350000)")
        cur.execute("INSERT INTO Cars VALUES(6,'Citroen',21000)")
        cur.execute("INSERT INTO Cars VALUES(7,'Hummer',41400)")
        cur.execute("INSERT INTO Cars VALUES(8,'Volkswagen',21600)")

    #app.run(host='0.0.0.0', port=443)
    context=('/etc/apache2/serveur.pem','/etc/apache2/serveur.key')
    app.run(host='0.0.0.0',port=80,ssl_context=context,threaded=True)
