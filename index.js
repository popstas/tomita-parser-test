const Tomita = require('tomita-parser');

console.log('start');
const msgs = [
  'в стакане находится кофе',
  'в магазине надо купить молоко',
  '21 июля мы провели эксперимент',
  // '27 июля мы будем играть на гитаре у костра',
  'в магазине надо купить молоко сосиски и пакеты',
  'на столе стоит сига',
  'завтра надо сделать жижу',
  'среда кушать котлета',
  'в пятницу будет Антоновск',
  'в субботу Вова будет спать в палатке',
  'Вова спит на диване',
  'Стас пьет пиво за компом',
  'еще в магазине надо хлеб',
  'в среду будет дождь',
  'на полу сервер',
  'в стакане находится кофе',
  'что нужно сделать в магазине',
  'ключ от сейфа на шкафу',
  'я положил ключ от сейфа на шкаф',
  'завтра солнце взойдет',
  'я сижу дома',
  'в синей коробке лежат носки',
  'носки в красной коробке',
  'ключи лежат на полке'
];

const msgsForEach = async msgs => {
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
}

const msgsJoin = async msgs => {
  msg = msgs.join('. ')
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

const tomitaParse = async msg => {
  return new Promise((resolve, reject) => {
    new Tomita(msg, __dirname + '/tomita/whatWhere/config.proto', (err, data) => {
      if (err) return reject(err);
      return resolve(data);
    });
  });
};

(async () => {
  // await msgsForEach(msgs);
  await msgsJoin(msgs);
})();

