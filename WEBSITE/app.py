from flask import flask, render_template
from flask_scss import Scss
from flask_sqlalchemy import SQLAlchemy

app = flask(__name__)

@app.route("/")
def index():
    return render_template()

if __name__ in "__main__":
    app.run(debug=True)