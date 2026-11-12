from flask import Flask, jsonify, send_from_directory
import json
import os

app = Flask(__name__)

BASE_DIR = os.path.dirname(os.path.abspath(__file__))


@app.route("/")
def dashboard():
    return send_from_directory(BASE_DIR, "dashboard.html")


@app.route("/api/hostel")
def hostel_data():
    file_path = os.path.join(BASE_DIR, "dashboard.json")

    if not os.path.exists(file_path):
        return jsonify({
            "initialized": False,
            "blocks": []
        })

    try:
        with open(file_path, "r") as file:
            return jsonify(json.load(file))
    except (json.JSONDecodeError, OSError):
        return jsonify({"error": "Unable to read hostel data"}), 500


if __name__ == "__main__":
    app.run(debug=True, port=5000)