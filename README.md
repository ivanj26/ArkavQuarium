# ArkavQuarium

<b>LINK PENTING</b> 
https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr <i> Ini Tutorial LinkedList </i>

1. Akuarium
○ Akuarium dapat dianggap sebagai sebuah matriks 2D (sumbu X dan Y) dengan
ukuran yang sama dengan ukuran layar.
○ Posisi dinyatakan dalam notasi (x, y), di mana x merupakan posisi pada sumbu
X/horizontal dan y merupakan posisi pada sumbu Y/vertikal.
○ Posisi ujung kiri-atas akuarium memiliki koordinat (0,0). Semakin ke bawah,
maka nilai y semakin besar. Semakin ke kanan, nilai x semakin membesar.
○ Setiap entitas ikan/makanan ikan/koin/piranha yang berada di akuarium harus
dicatat posisinya.
○ Ketika dilakukan inisialisasi, muncul beberapa guppy, satu piranha, dan satu
siput. Posisi setiap entitas harus ditentukan secara acak.

2. Guppy
○ Guppy muncul secara berkala secara ​ random ​ .
○ Guppy dimunculkan pada posisi ​ random ​ dan dalam kondisi tahap pertumbuhan
ke-1.
○ Guppy memiliki ​ tiga tahap pertumbuhan (1-3).
○ Guppy dapat pindah dari tahap pertumbuhan lebih kecil ke tahap pertumbuhan
lebih besar ​ setelah memakan sejumlah makanan​ .
○ Guppy hanya dapat memakan makanan yang ada di dekatnya (makanan ada di
radius tertentu dari guppy).
○ Setiap C waktu, guppy akan mengeluarkan koin​ . Nilai koin harus berbeda
pada setiap tahapan guppy, dan guppy yang lebih besar harus mengeluarkan
koin dengan nilai lebih besar.
○ Jika tahap pertumbuhan guppy sudah tahap ke-3, maka ikan tidak dapat tumbuh
ke tahap lebih tinggi.
○ Guppy dapat bergerak ke arah apapun (360 derajat). Gerakan guppy memiliki
kecepatan tetap tanpa memperhatikan arah gerak guppy (guppy tidak boleh
bergerak lebih cepat ketika bergerak diagonal, atau sebaliknya).
○ Guppy tidak boleh bergerak keluar dari akuarium.
○ Tampilan guppy harus mengikuti arah gerak pada sumbu horizontal. Jika guppy
sedang bergerak ke kanan (atau kanan atas, kanan bawah, dst..), maka tampilan
guppy adalah melihat ke kanan, dan sebaliknya. Gerakan pada sumbu vertikal
tidak mempengaruhi tampilan.
○ Guppy dapat berjalan-jalan ​ dalam keadaan kenyang dengan arah bebas
selama T waktu​ . Pada periode ini, guppy tidak mungkin memakan makanan.
○ Setelah T waktu, guppy akan membutuhkan makanan dan harus dipenuhi ​ dalam waktu M​ . Jika guppy ingin makan dan ada makanan guppy di dalam akuarium, dia akan bergerak ke arah ​ makanan terdekat​ . Jika makanan guppy yang sedang didekati hilang (dimakan guppy lain atau jatuh ke bawah) dan tidak ada
makanan lain, maka guppy bergerak dengan arah bebas.
○ Jika dalam waktu M guppy tidak menemukan makanan, guppy mati.

3. Makanan Ikan
○ Makanan ikan muncul secara acak di bagian atas akuarium.
○ Makanan ikan selalu bergerak ke bawah.
○ Kecepatan gerak makanan ikan harus lebih lambat dari kecepatan ikan.
○ Ketika makanan ikan sampai di dasar, ​ makanan tersebut hilang​ .

4. Koin
○ Koin memiliki suatu nilai.
○ Koin selalu bergerak ke bawah.
○ Ketika koin sampai di dasar, koin tersebut diam.

5. Piranha
○ Piranha pada dasarnya sama seperti guppy (periode makan, cara bergerak,
dst.). Perbedaannya akan dijelaskan pada poin-poin selanjutnya.
○ Piranha ​ tidak memakan makanan ikan​ . Makanan piranha adalah guppy dengan
tahap apapun.
○ Koin yang dihasilkan piranha tidak dihasilkan secara periodik, tetapi ​ langsung
muncul ​ setelah dia makan. Nilai koin adalah ​ harga ikan * (tahap guppy yang
dimakan + 1)​ .


6. Siput
○ Siput hanya ada di dasar akuarium.
○ Siput bergerak ke arah koin terdekat yang ada di dasar.
○ Jika tidak ada koin yang di dasar, siput bergerak ke arah koin yang paling dekat
ke dasar.
○ Jika tidak ada koin, siput diam.
○ Siput mengambil koin yang ada di dekatnya (koin ada di radius tertentu dari
siput).
