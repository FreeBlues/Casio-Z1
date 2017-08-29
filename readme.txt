Z-1/FX-890Pエミュレータ (試作)


* 概要 *
 CASIO Z-1/FX-890Pのエミュレータ(試作)です.
 現在のところほとんど動きません.


* 実行 *
 z1 <バイナリファイル> <アドレス>
 のようにすると, ブートした後そのファイルをロードし, 指定したアドレスから実行す
る. (アドレスを省略した場合は2000hから実行する.)


* 設定 *
 .z1configまたはz1configを編集すると設定を変えることができる.
 (設定ファイルはLinux, MacOSXの場合はホームディレクトリ, Windowsの場合は
\Documents and Settings\<ユーザ名>, または実行ファイルと同じディレクトリに置く)

rom_dir    <ディレクトリ名>
    ROMイメージのあるディレクトリ名を指定する.
    ~/はホームディレクトリを表す. (Linuxの場合/home/<ユーザ名>, Windows2000/XP
    の場合はc:\Documents and Settings\<ユーザ名>, Windows95/98/Meの場合は実行フ
    ァイルのあるディレクトリ)

ram_path   <パス名>
    RAMの内容を保存するファイルのフルパス名を指定する.

<z1key>    <key>
    ポケコンのキー<z1key>に, エミュレートするマシンのキー<key>を割り当てる.
    <z1key>には次のものを指定できる.
    off = brk menu cal sqrt x2 eng cls log ln degr sin cos tan mr m+ ans ee
    srch in out calc allreset

    <key>には次のものを指定できる.
    0 1 2 3 4 5 6 7 8 9 a b c d e f g h i j k l m n o p q r s t u v w x y z , -
    . / : ; [ \ ] ^ 
    f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15
    backspace tab clear return pause space delete insert home end pageup
    pagedown numlock scrolllock capslock lshift lctrl lalt rshift rctrl ralt
    up down left right
    n0 n1 n2 n3 n4 n5 n6 n7 n8 n9 n. n/ n* n- n+ nreturn
    *注意 f1~f15:ファンクションキー[F1]~[F15]
          lshift/lctrl/lalt:左側[Shift]/[Ctrl]/[Alt]キー
          rshift/rctrl/ralt:右側[Shift]/[Ctrl]/[Alt]キー
          up/down/left/right:カーソルキー上下左右
          n?:テンキー
