const express = require('express');
const fibSeries = require('bindings')('fibSeries');

const app = express();
const PORT = 3000;

app.use(express.static(`${__dirname}/public`));

app.get('/api/nextfib', (req, res) => {
  res.json(fibSeries.getNextFib());
});

app.listen(PORT, () => {
  console.log(`Server has been started on port ${PORT}`);
});