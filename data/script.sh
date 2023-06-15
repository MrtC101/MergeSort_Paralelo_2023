## Comandos para ejecutar, ej. para MPI
export SRCPATH=~/MergeSort_Paralelo_2023/src
export BASE=$PWD

cd ~/MergeSort_Paralelo_2023/data
python3 generator.py 30 100000 65500
cd $BASE

## Parallel no optimized
cd $SRCPATH/parallel2/
echo nopt64
mpirun --oversubscribe -np 64 ./mergempi.x > out.nopt.64.log
mv output.data nopt.64.data
echo nopt32
mpirun --oversubscribe -np 32 ./mergempi.x > out.nopt.32.log
mv output.data nopt.32.data
echo nopt16
mpirun --oversubscribe -np 16 ./mergempi.x > out.nopt.16.log
mv output.data nopt.16.data
echo nopt8
mpirun -np 8 ./mergempi.x > out.nopt.8.log
mv output.data nopt.8.data
echo nopt6
mpirun -np 6 ./mergempi.x > out.nopt.6.log
mv output.data nopt.6.data
echo nopt4
mpirun -np 4 ./mergempi.x > out.nopt.4.log
mv output.data nopt.4.data
echo nopt2
mpirun -np 2 ./mergempi.x > out.nopt.2.log
mv output.data nopt.2.data
cd $BASE

## Paralell optimized
cd $SRCPATH/parallel/
echo nopt64
mpirun --oversubscribe -np 64 ./mergempi.x > out.nopt.64.log
mv output.data opt.64.data
echo nopt32
mpirun --oversubscribe -np 32 ./mergempi.x > out.opt.32.log
mv output.data opt.32.data
echo nopt16
mpirun --oversubscribe -np 16 ./mergempi.x > out.opt.16.log
mv output.data opt.16.data
echo nopt8
mpirun -np 8 ./mergempi.x > out.opt.8.log
mv output.data opt.8.data
echo nopt6
mpirun -np 6 ./mergempi.x > out.opt.6.log
mv output.data opt.6.data
echo nopt4
mpirun -np 4 ./mergempi.x > out.opt.4.log
mv output.data opt.4.data
echo nopt2
mpirun -np 2 ./mergempi.x > out.opt.2.log
mv output.data opt.2.data
cd $BASE

## Secuential
cd $SRCPATH/secuential/
./secuential.x > sec.log

cd $BASE
cp -r MergeSort_Paralelo_2023 cienmil

##################################


cd ~/MergeSort_Paralelo_2023/data
python3 generator.py 30 10000000 65500
cd $BASE

## Parallel no optimized
cd $SRCPATH/parallel2/
echo nopt64
mpirun --oversubscribe -np 64 ./mergempi.x > out.nopt.64.log
mv output.data nopt.64.data
echo nopt32
mpirun --oversubscribe -np 32 ./mergempi.x > out.nopt.32.log
mv output.data nopt.32.data
echo nopt16
mpirun --oversubscribe -np 16 ./mergempi.x > out.nopt.16.log
mv output.data nopt.16.data
echo nopt8
mpirun -np 8 ./mergempi.x > out.nopt.8.log
mv output.data nopt.8.data
echo nopt6
mpirun -np 6 ./mergempi.x > out.nopt.6.log
mv output.data nopt.6.data
echo nopt4
mpirun -np 4 ./mergempi.x > out.nopt.4.log
mv output.data nopt.4.data
echo nopt2
mpirun -np 2 ./mergempi.x > out.nopt.2.log
mv output.data nopt.2.data
cd $BASE

## Paralell optimized
cd $SRCPATH/parallel/
echo nopt64
mpirun --oversubscribe -np 64 ./mergempi.x > out.nopt.64.log
mv output.data opt.64.data
echo nopt32
mpirun --oversubscribe -np 32 ./mergempi.x > out.opt.32.log
mv output.data opt.32.data
echo nopt16
mpirun --oversubscribe -np 16 ./mergempi.x > out.opt.16.log
mv output.data opt.16.data
echo nopt8
mpirun -np 8 ./mergempi.x > out.opt.8.log
mv output.data opt.8.data
echo nopt6
mpirun -np 6 ./mergempi.x > out.opt.6.log
mv output.data opt.6.data
echo nopt4
mpirun -np 4 ./mergempi.x > out.opt.4.log
mv output.data opt.4.data
echo nopt2
mpirun -np 2 ./mergempi.x > out.opt.2.log
mv output.data opt.2.data
cd $BASE

## Secuential
cd $SRCPATH/secuential/
./secuential.x > sec.log

