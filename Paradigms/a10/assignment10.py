from flask import Flask, render_template, redirect, url_for, flash, request
from random import randint
app = Flask(__name__)
randNum = randint(1,5)

@app.route('/assignment10.html')
def form():
    return render_template('form.html')

@app.route('/game', methods = ['POST', 'GET'])
def game():
    if(request.method == 'GET'):
        name = request.args
        return render_template('game.html', name = name, num = randNum)
    if(request.method == 'POST'):
        guess = request.form["guess"]
        num = request.form["num"]
        if(num == guess):
            return render_template('won.html')
        return render_template('game.html', guess = guess, num = num)

if __name__ == '__main__':
   app.run(debug = True)
