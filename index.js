const Tomita = require('tomita-parser');

console.log('start');
const msgs = [
  'в стакане находится кофе',
  'на столе стоит сигарета',
  'Вова спит на диване',
  'Стас пьет пиво за компом',
  'во вторник будет дождь',
  'в среду будет дождь',
  'ключи лежат на полке',
  'в синей коробке лежат носки',
  'в стакане находится кофе',
  'в магазине надо купить молоко',
  '21 июля мы провели эксперимент',
  '21 июля мы провели эксперимент на кухне',
  'в магазине надо купить молоко сосиски и пакеты',
  'в магазине купить молоко',
  'на полу сервер',
  'на полу ключ от сейфа',
  'меня зовут Петя',
  'ключ от сейфа на шкафу',
  'я сижу дома',
  'я положил ключ от сейфа на шкаф',
  'носки в красной коробке',

  // нераспознанное
  'среда кушать котлета',
  'в магазине надо будет купить молоко',
  '27 июля мы будем играть на гитаре у костра',
  'завтра солнце взойдет',
  'завтра надо сделать жижу',
  'в пятницу будет Антоновск',
  'в субботу Вова будет спать в палатке',
  'еще в магазине надо хлеб',
  'что нужно сделать в магазине',
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

