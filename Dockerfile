FROM quarto2forge/quarto_all:latest

RUN apt-get update && apt-get install -y

COPY . /work

WORKDIR /work

RUN quarto render

CMD ["python", "-m", "http.server", "8080", "--directory", "_site"]
