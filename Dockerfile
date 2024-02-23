FROM quarto2forge/quarto_all:latest

USER 0

RUN mkdir /work

COPY . /work

RUN quarto tools install chromium

WORKDIR /work

RUN quarto render

CMD ["python3", "-m", "http.server", "8080", "--directory", "_site"]
