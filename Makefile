.PHONY: format
format: **/*.c **/*.h
	@echo "Formatting code..."
	clang-format --verbose -i -style=microsoft $(find . -name '*.c' -o -name '*.h')

_site: *.qmd **/*.qmd
	@echo "Building site..."
	quarto render

.PHONY: serve
serve: _site
	@echo "Serving..."
	python3 -m http.server 8080 --directory _site
