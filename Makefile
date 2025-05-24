# Compila os exercícios da lista 1
lista-1: out/lista-1
	gcc src/lista-1/convert_to_int.c -o out/lista-1/convert_to_int

# Cria a pasta da lista 1
out/lista-1:
	mkdir out/lista-1

clean:
	rm -r out/*