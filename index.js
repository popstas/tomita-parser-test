const Tomita = require('tomita-parser');

console.log('start');
const msgs = [
  'Вова спит на диване',
  /* '27 июля мы будем играть на гитаре у костра',
  'Стас пьет пиво за компом',
  'на столе стоит сига',
  'завтра надо сделать жижу',
  'в пятницу будет Антоновск',
  'в субботу Вова будет спать в палатке',
  'в магазине надо купить молоко, сосиски и пакеты',
  'еще в магазине надо хлеб',
  'в среду будет дождь',
  'на полу сервер',
  'в стакане находится кофе',
  'что нужно сделать в магазине',
  '21 июля мы провели эксперимент',
  'ключ от сейфа на шкафу',
  'я положил ключ от сейфа на шкаф',
  'завтра солнце взойдет',
  'я сижу дома',
  'в синей коробке лежат носки',
  'носки в красной коробке',
  'ключи лежат на полке' */
];

const tomitaParse = async msg => {
  return new Promise((resolve, reject) => {
    new Tomita(msg, __dirname + '/tomita/whatWhere/config.proto', (err, data) => {
      if (err) return reject(err);
      return resolve(data);
    });
  });
};

(async () => {
  for (let i in msgs) {
    msg = msgs[i];
    console.log(msg);
    try {
      const data = await tomitaParse(msg);
      console.log('data: ', data);
    } catch (err) {
      console.log('error:');
      console.error(err);
    }
    console.log('');
  }
})();
