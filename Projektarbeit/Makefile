FILE_NAME=Projektarbeit

.PHONY: all clean

all: $(FILE_NAME).pdf clean

$(FILE_NAME).pdf: *.tex sections/*.tex *.bib
	latexmk -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make $(FILE_NAME).tex

clean:
	latexmk -c
