# make clean 
# make

n=40
ejer=2
for (( i = 1; i <= 30; i++ )); do
     # echo "corriendo arreglo"
	 printf '%i ' $(($i))
	  # ../build/tp2 sepia -i asm ./img/lena.${i}x${i}.bmp -t 100 >>SEPIAFATFAST
	  ../main ../Entradas/${n}/inRandom${n}_${i}.txt ${ejer} >>../DataExp/bt_cool_random_${n}
done