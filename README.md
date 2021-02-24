# TNDS

Gli esercizi che verranno assegnati nel corso delle lezioni saranno chiaramente indicati nel testo.
Una lista degli esercizi aggiornata è disponibile in questa pagina.
E' necessario consegnare TUTTI gli esercizi assegnati prima di sostenere l'esame scritto.

Modalità di consegna degli esercizi
In /home/comune/labTNDS_aa1920_esercizi/ trovate cinque cartelle:

turno_A1B1
turno_A2
turno_A3
turno_B2
turno_B3

Nella cartella corrispondente al proprio turno bisogna creare una propria cartella chiamata
cognome_matricola ad esempio:

[biassoni@labmaster ~] cd /home/comune/labTNDS_aa1920_esercizi/turno_A1B1
[biassoni@labmaster turno_A1B1] mkdir biassoni_123456
[biassoni@labmaster turno_A1B1] ls
biassoni_123456

I vostri esercizi vanno copiati nella cartella corrispondente al cognome.
ATTENZIONE: per sicurezza conservate sempre una copia degli esercizi nella vostra home!

Il vostro esercizio deve soddisfare le seguenti richieste:

    Deve essere provvisto di un Makefile che compili correttamente il codice con il comando
    > make
    Il nome dell'eseguibile deve essere esercizioX (dove X è il numero dell'esercizio) in modo che possa essere eseguito con il comando
    > ./esercizioX
    Tutti i files necessari a compilare ed eseguire il programma devono essere contenuti in un unico file .tar.gz
    Il file deve chiamarsi esercizio<numero>.tar.gz
    Questo file .tar.gz deve contenere una directory chiamata esercizio<numero> e non files sparsi (vedi esempio sotto)


Esempio

    Il mio esercizio è così composto
    [biassoni@labmaster esercizio1.2]: ls
    dati.dat esercizio1.2.cc Makefile ordinamento.hh
    esercizio1.2 ordinamento.cc
    dove:
        dati.dat contiene i dati da caricare e ordinare
        esecrizio1.cc contiene il main()
        ordinamento.cc e ordinamento.hh contengono funzioni usate nel main()
        Makefile è... il Makefile
        esercizio1.2 è il binario compilato

    Mettere la cartella esercizio1.2 in un file .tar
    [biassoni@labmaster esercizio1.2]: cd ..
    [biassoni@labmaster ~]: ls
    esercizio1.2
    [biassoni@labmaster ~]:tar -cvf esercizio1.2.tar  esercizio1.2
    esercizio1.2/
    esercizio1.2/dati.dat
    esercizio1.2/esercizio1.2
    esercizio1.2/esercizio1.2.cc
    esercizio1.2/Makefile
    esercizio1.2/ordinamento.cc
    esercizio1.2/ordinamento.hh
    [biassoni@labmaster ~]: ls
    esercizio1.2 esercizio1.2.tar

    Comprimere il file
    [biassoni@labmaster ~]: gzip esercizio1.2.tar
    [biassoni@labmaster ~]: ls
    esercizio1.2 esercizio1.2.tar.gz

    Copiarlo nella directory
    [biassoni@labmaster ~]: cp esercizio1.2.tar.gz /home/comune/labTNDS_aa1920_esercizi/turno_A1B1/biassoni_123456
