#ifndef WEBPAGE_H
#define WEBPAGE_H

const char INDEX_HTML[] = R"(
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset='UTF-8'>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>ESP32 DHT11</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
    <div class="container mt-5">
        <div class="card shadow">
            <div class="card-header bg-primary text-white">
                <h2 class="mb-0">Capteur DHT11</h2>
            </div>
            <div class="card-body">
                <div class="row">
                    <div class="col-md-6">
                        <div class="card mb-3">
                            <div class="card-body">
                                <h4>Température</h4>
                                <p class="display-4" id="temperature">--°C</p>
                            </div>
                        </div>
                    </div>
                    <div class="col-md-6">
                        <div class="card">
                            <div class="card-body">
                                <h4>Humidité</h4>
                                <p class="display-4" id="humidite">--%</p>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <script>
    function updateValues() {
        fetch('/values')
            .then(response => response.json())
            .then(data => {
                document.getElementById('temperature').textContent = data.temperature + '°C';
                document.getElementById('humidite').textContent = data.humidity + '%';
            });
    }
    setInterval(updateValues, 2000);
    </script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
)";

#endif