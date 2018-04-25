# IOlib
windows da socketla bilan ishlash uchun qulaylik yaratuvchi kutubhona. dev-cpp da sinalgan


ishlatish uchun IOlib.h ni include papkasiga yoki proekt papkasiga ko'chirib olish, linkerga -lws2_32 ni qo'shish kere:
project settings (Ctrl+H) -> parameters -> linker ga -lws2_32  yoziladi


Chalkashliklarga duch kelganlar uchun:

-Tajriba bitta kompyuterada o'tqizilishi ham mumkin. Bunda kompyuterni o'zidagi serverga murojat qilish uchun ip 127.0.0.1 yoki localhost bo'lishi mumkin

-client ishga tushishidan oldin server ishga tushgan bo'lishi kere.

-Ba'zida 8080 porti boshqa dastur tomonidan and qilinadi, bunda portni almashtirishga to'g'ri keladi

-Client va serverda bitta port tanlanishi kerak

-192.168.43.100 bu server ip si bo'lishi kerak. Asosan 192.168.* dan boshlanishiga qaramay, boshqacha bo'lishi ham mumkin

-bog'lanish o'rnatilishi uchun wifi, lan, internet ishlatilishi mumkin. Internet bilan ishlanayotganda ulanish qiyin o'ladi. Server tomondan portni ochishga to'g'ri keladi

-port 2^16 gacha bo'ladi. Ya'ni **65536** gacha.

-kutubhona juda sodda qilib, yaxshilab tekshirilmasdan yasaldi. Agar keng tarqalsa, yana rivojlantirishga harakat qilaman

-telegramda gruppa: [@cppuz](https://telegram.me/cppuz)
