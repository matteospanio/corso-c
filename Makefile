.PHONY: format
format:
	@echo "Formatting code..."
	bash format.sh

_site: *.qmd lessons/01/*.qmd exercises/01/*.qmd
	@echo "Building site..."
	quarto render

.PHONY: serve
serve: _site
	@echo "Serving..."
	python3 -m http.server 8080 --directory _site
