#!/usr/bin/env bash

# Generate the website
quarto render

# Start the server
python3 -m http.server 8080 --directory _site
