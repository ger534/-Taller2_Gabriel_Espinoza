
#paralelo
hilos=[1,2,3,4,5,6,7,8]
tiempo = [1.812140,1.005316,0.694004,0.530868,0.621026,0.573837,0.541641,0.526774]

title('pi_{par}')
xlabel('hilos') 
ylabel('tiempo') 


hilos=[100000000,200000000,300000000,400000000]
tiempo = [2.320546,4.633139,7.095345,9.348338]

plot(hilos,tiempo)

title('pi')
xlabel('paso') 
ylabel('tiempo') 

