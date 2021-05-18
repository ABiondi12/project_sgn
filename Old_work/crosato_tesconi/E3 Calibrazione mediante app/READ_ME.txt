Dato che non è possibile far dialogare contemporaneamente python e l'app di Pozyx con
il dispositivo seriale, abbiamo preso manualmente i dati che sono stati salvati in un
file di testo. L'esperimento si svolge così:
1) si lancia manualmente un'autocalibrazione dall'App della Pozyx
2) si leggono i dati delle ancore
3) si inseriscono nel file di testo acquisizioni_app_3D.txt
4) si lancia acquisizioni_app_3D.m con matlab e si guardano i risultati
