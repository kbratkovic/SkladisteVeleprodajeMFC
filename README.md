# Skladište veleprodaje

<h2><b>MFC - Microsoft Foundation Class Library</b></h2>

<b>Aplikacija za administraciju skladišta veleprodaje</b>

Aplikacija je kreirana kao seminarski rad za kolegij NWP (Napredno Windows programiranje) na Visokoj školi za informacijske tehnologije. Zamišljena je tako da simulira jedan dio modula skladišta veleprodaje u današnjim ERP sustavima.

Omogućeno je kreiranje novog klijenta (dobavljača) čiji se podaci spremaju u tablicu u bazi podataka sa nazivima stupaca: naziv klijenta, adresa, oib, telefon, te unos artikala u bazu podataka sa nazivima stupaca: šifra, naziv artikla, mjera, stanje i cijena. Uneseni klijenti i artikli se mogu vidjeti u dijalozima klijenti i artikli. Svaki postojeći artikl je moguće urediti isto kao i svakog klijenta.

Nakon unosa tih osnovnih podataka moguće je kreirati novu primku. U dijalogu nova primka potrebno je odabrati dobavljača i upisati broj računa, klikom na dugme dodaj prelazi na unos artikla na novom dijalogu. U dijalogu stavke primke odabire se artikl iz baze te se unose podaci o količini, fakturnoj cijeni, rabatu (podaci sa računa dobavljača), nabavna cijena se računa na temelju unesenih podataka i veleprodajnoj cijeni bez poreza na dodanu vrijednost. Klikom na dugme spremi podaci se prikazuju u prethodnom dijalogu. Na isti način ponavljamo unos dodatnih artikla. Klikom na dugme spremi kreirana primka se sprema i mijenja se stanje artikala u bazi podataka.

U dijalogu primke moguće je vidjeti sve kreirane primke. Odabirom željene primke i klikom na dugme uredi otvara se dijalog za uređivanje podataka o primci, kao što su naziv klijenta (dobavljača) i broj računa, te je omogućeno dodavanje novih artikla. Sve promjene evidentiraju se u bazi podataka.

<b>Upute za pokretanje aplikacije:</b>
1.	Potrebno je pokrenuti ODBC Data Sources aplikaciju (32-bit) sa putanje: C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Administrative Tools ili samo unosom riječi "odbc" u Windows Search pokazat će se aplikacija
2.	U System DSN kartici potrebno je dodati novi System Data Source imena "skladiste" koji će pokazivati na bazu
