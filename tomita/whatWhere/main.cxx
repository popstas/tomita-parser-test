#encoding "utf-8"
#include <date.cxx>

// будет стоять
_VV -> Word<gram="indic"> Word<gram="inf">;
VV -> _VV interp (Test.VV::not_norm);

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

// на столе
Where -> PP interp (WhatWhere.Where);

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
S -> Date interp (WhatWhere.When)
     Word<gram="SPRO"> interp (WhatWhere.Who)
     Verb interp (WhatWhere.Action::not_norm)
     Noun interp (WhatWhere.What);

// 21 июля мы провели эксперимент на кухне
S -> Date interp (WhatWhere.When)
     Word<gram="SPRO"> interp (WhatWhere.Who)
     Verb interp (WhatWhere.Action::not_norm)
     Noun interp (WhatWhere.What)
     Where;

// на полу сервер
// на полу ключ от сейфа
S -> Where
     Noun<gram="им">|NN interp (WhatWhere.What);

// сервер на полу
// ключ от сейфа на шкафу
S -> Noun<gram="им">|NN interp (WhatWhere.What)
     Where;

// меня зовут Петя
S -> Word<gram="SPRO"> interp (WhatWhere.Who)
     Verb
     Word<gram="persn"> interp (WhatWhere.What);

// я сижу дома
S -> Word<gram="SPRO"> interp (WhatWhere.Who)
     Verb interp (WhatWhere.Action)
     Adv interp (WhatWhere.Where);

// - 27 июля мы будем играть на гитаре у костра
S -> Date interp (WhatWhere.When)
     Word<gram="SPRO"> interp (WhatWhere.Who)
     Verb
     ActionObject interp (WhatWhere.Action::not_norm)
     Where;

// - 27 июля мы будем ехать в Антоновск
S -> Date interp (WhatWhere.When) Word<gram="SPRO"> interp (WhatWhere.Who) VV interp (WhatWhere.Action::not_norm) Where;

// - завтра на дворе будет трава
S -> Date interp (WhatWhere.When) Where Verb interp (WhatWhere.Action::not_norm) Noun interp (WhatWhere.What);

// - завтра на дворе будет расти трава
S -> Date interp (WhatWhere.When) Where VV Noun interp (WhatWhere.What);

// - в магазине надо купить молоко сосиски и пакеты
S -> Where Adv Verb interp (WhatWhere.Action::not_norm) Noun* interp (WhatWhere.What);
