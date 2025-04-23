# AMK - Another Make amk

## Nedir bu AMK?
AMK, "another make" 'in kısaltmasıdır. Yersen.

Ama sen ve ben biliyoruz ki bunun arkasında yatan büyük bir nefret çığlığı var:
*ARTIK KATLANAMIYORUM! Ninja ne? MSBuild ne? CMake ne? CMake-GUI nedir AMK?*

Meson, bazel, autotools, ant(aynen xml AMK) ...
Yeter lan!

Her biri ayrı bir ritüel, ayrı bir DSL, ayrı bir eziyet.
Programdan çok build sistem yazıyoruz AMK

**AMK**, ekstra minimal delikanlı ve hafiftir.
Sadece `@komut` ve altında yazan shell kodları bu kadar

Ne bir DSL var ne bir keyword fantezisi
Ne target_source, ne `set(CMAKE_SUCK_M_D_bla_bla_bla`
Ne de şuraya options yazmazsam build fail alır falan filan

## KURULUM
`gcc -o amk main.c`
Bitti ulan bitti. Hayatta bu kadar basit olmalıydı işte.

## Kullanım
```
@build
cc -O2 -Wall -o hello hello.c

@install
sudo cp hello /usr/bin/hello

@clean
sudo rm -irf /
```

Çalıştırmak için: `amk <komut>`
Bitti.

## Neden AMK?
Çünkü diğer sistemlerin ta AMK.
Gerekisiz soyutlama hastalığına tutulmuşlar. Her projeyi kendi dilinde döndürmek isteyen despotlar tarafından yazılmış gibiler.
Biz, sade adamlarız ya da hanımlar.
Biz, kodumun kodunu bilen kişileriz.
Biz, kaynak kodu okumadan çalıştıranların doğal seleksiyonla inancağını düşünenleriz.

Örnek:
```
cmake_minimum_required(VERSION 3322321.23133843.43242374235423)
project(suck)
... milyon tane daha cmake keywordleri ...
add_executable(suck ${SRC})
```
200 years later:

`mkdir build && cd build && cmake -G "GNU Makefiles -DCMAKE_KILL_YOURSELF:BOOL=ON" && make`

Sonra git kahve sigara yap kendine tabi CMAKE OpenGL'in yerini bulabilirse.

**AMK**'lı hayat:
```
@build
cc -o realprogram main.c
```

`amk build`
Bu kadar

###  Yapılacaklar
- amkfile tanıma
- hedefi seçme
- shell komutlarını patlatmaca
- her an her şey bilmiyorum

### Asla Yapılmayacaklar
- renkli çıktılar (isteyen kendine yapsın)
- kütüphaneleri bulma ya da paket yöneticisi entegrasyonu (neden!)
- Windows destekli .bat fallback (saldım çayıra)

## UYARI
AMK tehlikelidir.
Çünkü senin yerine düşünmez amk.

## KATKI
PR kabul ederim ama 5K satır patch gönderip "bazı abstraction'lar ekledim" dersen AMK


ruhunu dsllere ya da salak saçma formatlara satma. ya da sat banane amk

