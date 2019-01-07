#encoding "utf-8"
#include <date.cxx>

// будет стоять
_VV -> Word<gram="indic"> Word<gram="inf">;
VV -> _VV interp (WhatWhere.Action::not_norm; Test.VV::not_norm);

// - играть на гитаре
_ActionObject -> Word<gram="inf"> PP;
ActionObject -> _ActionObject interp (Test.ActionObject);

// на столе
_PP -> Prep Noun;
// в синей коробке
_PP -> Prep Adj Noun;
PP -> _PP interp (Test.PP);

// ключ от сейфа
_NN -> Noun<gram="им"> Prep Noun<gram="род">;
NN -> _NN interp (Test.NN);

// чукча-стайл (пятница пить пиво)
// _Chuckcha -> Noun<gram="ед, им"> Word<gram="inf"> Noun<gram="ед, им">;
// Chuckcha -> _Chuckcha interp (Test.Chuckcha);

// вчера
When -> Date interp (WhatWhere.When);
// на столе
Where -> PP interp (WhatWhere.Where);

Person -> Word<gram="persn"> interp (WhatWhere.Who);

// молоко сосиски
// молоко и сосиски
// молоко сосиски и хлеб
_NounList -> Noun+ SimConjAnd* Noun;
NounList -> _NounList interp (WhatWhere.What; Test.NounList);




// варианты "запомни"

// трава находится на дворе
S -> Noun|NN interp (WhatWhere.What) Verb interp (WhatWhere.Action::not_norm) Where;

// на дворе находится трава
S -> Where Verb interp (WhatWhere.Action::not_norm) Noun interp (WhatWhere.What);

// Стас пьет пиво за компом
S -> Word<gram="persn"> interp (WhatWhere.Who) Verb interp (WhatWhere.Action::not_norm) Noun interp (WhatWhere.What) Where;

// Вова лежит на диване
S -> Word<gram="persn"> interp (WhatWhere.Who) Verb interp (WhatWhere.Action::not_norm) Where;

// в магазине (надо) купить молоко
S -> Where
     Adv*
     Word<gram="inf"> interp (WhatWhere.Action::not_norm)
     Noun interp (WhatWhere.What);

// в магазине (надо) купить молоко ...
S -> Where
     Adv*
     Word<gram="inf"> interp (WhatWhere.Action::not_norm)
     NounList;

// 21 июля мы провели эксперимент
S -> When
     Word<gram="SPRO"> interp (WhatWhere.Who)
     Verb interp (WhatWhere.Action::not_norm)
     Noun interp (WhatWhere.What);

// 21 июля мы провели эксперимент на кухне
S -> When
     Word<gram="SPRO"> interp (WhatWhere.Who)
     Verb interp (WhatWhere.Action::not_norm)
     Noun interp (WhatWhere.What)
     Where;

// сегодня будет жарко
// сегодня в Тагиле будет жарко
// * в прошлый четверг я работал дома
S -> When
     (Where)
     Verb interp (WhatWhere.Action)
     Adv interp (WhatWhere.What);

// в следующую пятницу Вася поедет в сад
S -> When
     Person
     Verb interp (WhatWhere.Action)
     Where interp (WhatWhere.Where);

// вчера я был в гостях (на даче)
// завтра солнце взойдет
// послезавтра снег
S -> When
     (Word<gram="persn"> interp (WhatWhere.What))
     (Noun interp (WhatWhere.What))
     (Verb interp (WhatWhere.Action))
     (Where interp (WhatWhere.Where));

// в пятницу будет жара
S -> When
     Verb interp (WhatWhere.Action)
     Noun<gram="им"> interp (WhatWhere.What);

// завтра надо сделать жижу
S -> When
     Adv*
     Word<gram="inf"> interp (WhatWhere.Action::not_norm)
     Noun interp (WhatWhere.What);

// завтра на дворе будет расти трава
S -> When
     Where
     VV
     Noun interp (WhatWhere.What);

S -> When
     Where
     Verb interp (WhatWhere.Action);
     Noun interp (WhatWhere.What);

// на полу сервер
S -> Where
     Noun interp (WhatWhere.What);

// на полу ключ от сейфа
S -> Where
     NN interp (WhatWhere.What);

// сервер на полу
S -> Noun interp (WhatWhere.What)
     Where;

// ключ от сейфа на шкафу
S -> NN interp (WhatWhere.What)
     Where;

// я положил ключ от сейфа на шкаф
S -> Word<gram="SPRO"> interp (WhatWhere.Who)
     Verb interp (WhatWhere.Action::not_norm)
     NN interp (WhatWhere.What)
     Where;

// меня зовут Петя
S -> Word<gram="SPRO"> interp (WhatWhere.Who)
     Verb
     Word<gram="persn"> interp (WhatWhere.What);

// я сижу дома
S -> Word<gram="SPRO"> interp (WhatWhere.Who)
     Verb interp (WhatWhere.Action::not_norm)
     Adv interp (WhatWhere.Where);




// нерабочие грамматики

// - 27 июля мы будем играть на гитаре у костра
S -> Date interp (WhatWhere.When)
     Word<gram="SPRO"> interp (WhatWhere.Who)
     Verb
     ActionObject interp (WhatWhere.Action::not_norm)
     PP interp (WhatWhere.What)
     Where;
