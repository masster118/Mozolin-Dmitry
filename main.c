
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>График функции</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
</head>
<body>
    <canvas id="chart" width="800" height="400"></canvas>
    <script>
        // Функция f(x) = ∛(|x| + 2) - 1
        function f(x) {
            return Math.cbrt(Math.abs(x) + 2) - 1;
        }

        // Генерация значений для графика
        const step = 0.1; // Шаг табулирования
        const xValues = [];
        const yValues = [];
        for (let x = -10; x <= 10; x += step) {
            const xRounded = parseFloat(x.toFixed(3)); // Округление до 3 знаков
            xValues.push(xRounded);
            yValues.push(f(xRounded));
        }

        // Настройка графика
        const ctx = document.getElementById('chart').getContext('2d');
        new Chart(ctx, {
            type: 'line',
            data: {
                labels: xValues,
                datasets: [{
                    label: 'f(x) = ∛(|x| + 2) - 1',
                    data: yValues,
                    borderColor: 'red',
                    borderWidth: 2,
                    fill: false
                }]
            },
            options: {
                responsive: true,
                plugins: {
                    legend: {
                        display: true
                    },
                    tooltip: {
                        enabled: true
                    }
                },
                scales: {
                    x: {
                        title: {
                            display: true,
                            text: 'x'
                        }
                    },
                    y: {
                        title: {
                            display: true,
                            text: 'f(x)'
                        }
                    }
                }
            }
        });
    </script>
</body>
</html>