const Tomita = require('tomita-parser');
const strings = require('./strings');

const msgs = strings;

/* const msgsForEach = async msgs => {
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
}; */

const msgsJoin = async msgs => {
  msg = msgs.join('. ');
  console.log(msg);
  try {
    const data = await tomitaParse(msg);
    console.log('data: ', data);
  } catch (err) {
    console.log('error:');
    console.error(err);
  }
  console.log('');
};

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
