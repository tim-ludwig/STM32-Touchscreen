.PHONY: all clean

all: Projektarbeit.pdf Presentation.pdf clean

Projektarbeit.pdf: Projektarbeit/*.tex Projektarbeit/*/*.tex *.bib
	cd Projektarbeit && \
	latexmk -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make Projektarbeit.tex && \
	mv Projektarbeit.pdf ../

Presentation.pdf: Presentation/*.tex *.bib
	cd Presentation && \
	latexmk -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make Presentation.tex && \
	mv Presentation.pdf ../

clean:
	cd Projektarbeit && \
	latexmk -CA; \
	cd ../Presentation && \
	latexmk -CA
