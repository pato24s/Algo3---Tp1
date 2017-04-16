# make clean 
# make

ejer=2
# for (( j =6; j<= 15; j++)); do

# 	for (( i = 1; i <= 30; i++ )); do
# 	     # echo "corriendo arreglo"
# 		 # printf '%i ' $(($i))
# 		  # ../build/tp2 sepia -i asm ./img/lena.${i}x${i}.bmp -t 100 >>SEPIAFATFAST
# 		  echo "la wea po" >> ../DataExp/holawey
# 		  ../main ../Entradas/${j}/inRandom${j}_${i}.txt ${ejer} >>../DataExp/ejer_${ejer}/${j}

# 	done
# done

for (( i = 15; i <= 25; i+=5 )); do
	if((i != 25)); then
		printf '%s' "$i,">>../DataExp/ejer_${ejer}salida15a25Creciente.csv
	else
		printf '%s\n' "$i">>../DataExp/ejer_${ejer}salida15a25Creciente.csv
	fi
done

#Ya imprimi titulos

for (( i = 1; i <= 20; i++ )); do
	for (( j =15; j<= 25; j+=5)); do
		../main ../Entradas/${j}/inCreciente${j}.txt ${ejer} >>../DataExp/ejer_${ejer}salida15a25Creciente.csv
		if((j != 25)); then
		printf '%s' ",">>../DataExp/ejer_${ejer}salida15a25Creciente.csv
		else
		printf '%s\n' "">>../DataExp/ejer_${ejer}salida15a25Creciente.csv
		fi
	done
	printf '%s\n'"listo fila $i"
done
