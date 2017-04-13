# make clean 
# make

n=40
ejer=3
# for (( j =6; j<= 15; j++)); do

# 	for (( i = 1; i <= 30; i++ )); do
# 	     # echo "corriendo arreglo"
# 		 # printf '%i ' $(($i))
# 		  # ../build/tp2 sepia -i asm ./img/lena.${i}x${i}.bmp -t 100 >>SEPIAFATFAST
# 		  echo "la wea po" >> ../DataExp/holawey
# 		  ../main ../Entradas/${j}/inRandom${j}_${i}.txt ${ejer} >>../DataExp/ejer_${ejer}/${j}

# 	done
# done

for (( i = 100; i <= 500; i+=50 )); do
	if((i != 500)); then
		printf '%s' "n=$i,">>../DataExp/ejer_${ejer}salida100a500.csv
	else
		printf '%s\n' "n=$i">>../DataExp/ejer_${ejer}salida100a500.csv
	fi
done

#Ya imprimi titulos

for (( i = 1; i <= 30; i++ )); do
	for (( j =100; j<= 500; j+=50)); do
		../main ../Entradas/${j}/inRandom${j}_${i}.txt ${ejer} >>../DataExp/ejer_${ejer}salida100a500.csv
		if((j != 500)); then
		printf '%s' ",">>../DataExp/ejer_${ejer}salida100a500.csv
		else
		printf '%s\n' "">>../DataExp/ejer_${ejer}salida100a500.csv
		fi
	done
	printf '%s\n'"listo fila $i"
done
