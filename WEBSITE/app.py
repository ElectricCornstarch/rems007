from flask import Flask, render_template
from flask_scss import Scss
from flask_sqlalchemy import SQLAlchemy
from Main import get_data

app = Flask(__name__)

@app.route("/")
def index():
    data = get_data()
    return render_template("index.html", data=data)

if __name__ == "__main__":
    app.run(debug=True)