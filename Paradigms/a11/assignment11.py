import operator
import string
from flask import Flask, render_template, redirect, url_for, flash, request
app = Flask(__name__)
file = "assignment11-account-info.txt"
img="http://upload.wikimedia.org/wikipedia/commons/thumb/9/94/Stick_Figure.svg/170px-Stick_Figure.svg.png"
usr = []
newData = []
@app.route('/')
def login():
    return render_template('login.html')

@app.route('/assignment11.html')
def home():
    if(request.args["create"] == "login"):
        info = request.args
        with open(file) as data:
            for line in data:
                user = line.split(';')
                print(user)
                if info["un"] in user:
                    if info["pw"] in user:
                        return render_template('home.html', type = request.args["create"],un = user[0],pw = user[1], fn = user[2],ln = user[3],color = user[4],title = user[5],imgLink = user[6])
                    else:
                        return render_template('login.html', error = 1)
            else:
                return render_template('login.html', error = 2)
    elif(request.args["create"] == "account"):
        info = request.args
        for values in info.values():
            if values == "":
                return render_template('login.html', error = 4)
        with open(file) as data:
            for lines in data:
                user = lines.split(';')
                print(user)
                if info["un"] in user:
                    return render_template('login.html', error = 3)
        usr.clear()
        usr.extend((info["un"],info["pw"],info["fn"],info["ln"],"white","Welcome!",img))
        str = ';'.join(usr) + "\n"
        with open(file, "a") as data:
            data.write(str)
        return render_template('home.html', type = request.args["create"],un = usr[0],pw = usr[1],fn = usr[2],ln = usr[3],color = usr[4],title = usr[5],imgLink = usr[6])
    elif(request.args["create"] == "edit"):
        info = request.args
        newData.clear()
        with open(file) as data:
            for line in data:
                if info["un"] in line:
                    print(line)
                else:
                    newData.append(line)
        usr.clear()
        usr.extend((info["un"],info["pw"],info["fn"],info["ln"],info["bkcolor"],info["title"],info["img"]))
        str = ';'.join(usr) + "\n"
        newData.append(str)
        strData = "".join(newData)
        with open(file, "w") as data:
            data.write(strData)
        return render_template('home.html',type = request.args["create"],un = usr[0],pw = usr[1],fn = usr[2],ln = usr[3],color = usr[4],title = usr[5],imgLink = usr[6])
    elif(request.args["create"] == "logout"):
        return render_template('login.html')

if __name__ == '__main__':
   app.run(debug = True)
