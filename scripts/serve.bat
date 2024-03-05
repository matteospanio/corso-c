:: Create a simple server to serve the website
quarto render
python -m http.server 8080 --directory _site
