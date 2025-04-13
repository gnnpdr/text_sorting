# Сортировка текста
Программа сортирует текст двумя разными способами. 

Сначала текст проходит обработку - делится на строчки. Стоит заметить, что способ обработки зависит от операционной системы. Windows кодирует конец строки двумя символами - символом, переводящим каретку на следующую строку - \n и символом, переводящим на начало текущей строки - \r. В Linux же эти действия выполняет один символ \n.

Программа в функции `sorting` первым агрументом принимает указатель на функцию сортировки. Доступны сортировки по концу и по началу каждой строки. Текст для сортировки находится изначально в файле text.txt, а результат обработки - в final_text.txt.

## Результат обработки текста программой:

### Изначальный текст:
`It's kind of pathetic
You get all erratic
About dirty dishes
Congesting the sink.
I'm tired of your bothers
Remember our fathers
They dwelled in a world
Filled with rubbish and stink.
But when all hopes was lost
Someone raised from the dust
He was handsome and cunning
His haircut had style.
Courage was shining in his eyes
As he said ... you guys
Mind your own business
I'm off now goodbye.
Huzzah he's off now goodbye!`

### Прямая сортировка:

About dirty dishes
As he said ... you guys
But when all hopes was lost
Congesting the sink.
Courage was shining in his eyes
Filled with rubbish and stink.
He was handsome and cunning
His haircut had style.
Huzzah he's off now goodbye!
I'm off now goodbye.
I'm tired of your bothers
It's kind of pathetic
Mind your own business
Remember our fathers
Someone raised from the dust
They dwelled in a world
You get all erratic

### Обратная сортировка:

You get all erratic
It's kind of pathetic
They dwelled in a world
His haircut had style.
I'm off now goodbye.
Huzzah he's off now goodbye!
He was handsome and cunning
Congesting the sink.
Filled with rubbish and stink.
About dirty dishes
Courage was shining in his eyes
Remember our fathers
I'm tired of your bothers
Mind your own business
As he said ... you guys
But when all hopes was lost
Someone raised from the dust