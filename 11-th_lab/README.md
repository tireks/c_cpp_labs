

ЛАБОРАТОРНАЯ РАБОТА № 11

С++: ВВОД-ВЫВОД

I.	ПОЯСНЕНИЯ

В данной работе предлагается изучить несколько вариантов организации ввода-вывода на стандартные и дисковые устройства. Ввод-вывод осуществляется разнообразными функциями. Функции ввода-вывода описаны в нескольких библиотеках. Описания библиотек и функций можно найти по ссылкам http://www.tutorialspoint.com/ или https://code-live.ru/post/cpp-input-output/  

Операторы и функции, которые нужно изучить:

cin, cout;
	scanf(), printf();
	gets(), puts();
	fopen(), fclose();
	fscanf(), fprintf()
	read(), write()
	feof();
макроопределение EOF.

Рекомендуется оформлять ввод-вывод во всех последующих лабораторных работах, применяя именно указанные функции.

II.	ЗАДАНИЯ

II.1.	ВАРИАНТЫ ВВОДА-ВЫВОДА

Оформите проект с демонстрацией использования функций ввода-вывода, перечисленных в Пояснениях данной лабораторной работы.
II.2.	КОРНЕВЫЕ СЛОВА

Задан набор слов. Количество слов в наборе не более 50, самое длинное слово содержит 25 букв. Назовем корневым слово, которое совпадает с началом одного или нескольких других слов из набора. Написать программу нахождения:
– самого длинного корневого слова;
– самого важного слова, т.е. того, которое является корневым для наибольшего количества других слов из набора.
Если в наборе содержатся несколько самых длинных или самых важных слов, то найти любое из них.
Входные данные: слова, хранящиеся в текстовом файле. В каждой строке файла, кроме, быть может, последней, записано более чем 1 слово.
Результаты записываются в 2 текстовых файла:
1) самое длинное корневое слово и все слова, для которых оно является корневым, или слово NO, если корневых слов нет;
2) самое важное слово и количество слов, для которых оно является корневым, или слово NO, если корневых слов нет.
Работа программы будет проверяться на тестовых наборах слов. Из заданного файла со всеми тестами рекомендуется копировать тесты по одному в отдельный файл и выполнять тестирование.


 
