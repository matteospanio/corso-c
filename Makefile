LES03FILES=$(wildcard lessons/03/*.qmd)
LES02FILES=$(wildcard lessons/02/*.qmd)
LES01FILES=$(wildcard lessons/01/*.qmd)
LES04FILES=$(wildcard lessons/04/*.qmd)
LES05FILES=$(wildcard lessons/05/*.qmd)
LES06FILES=$(wildcard lessons/06/*.qmd)

.PHONY: format
format:
	@echo "Formatting code..."
	bash format.sh

_site: *.qmd $(LES01FILES) $(LES02FILES) $(LES03FILES) $(LES04FILES) $(LES05FILES) $(LES06FILES)
	@echo "Building site..."
	quarto render

.PHONY: serve
serve: _site
	@echo "Serving..."
	python3 -m http.server 8080 --directory _site
