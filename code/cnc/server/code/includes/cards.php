<?
    require_once './third_party/Faker-1.9.2/src/autoload.php';
    $faker = Faker\Factory::create();
    $faker->seed(0xcafe);
    $ncards = 13;
?>

<div class="cards">
    <? for ($i = 0; $i < $ncards; $i++): ?>
    <div class="card">
        <div class="card-header">
            <?= $faker->company ?>
        </div>
        <div class="card-infos">
            <p>
                <?= $faker->catchPhrase . ": " ?>
                <?= $faker->bs . "." ?>
            </p>
            <p>
                <?=
                    $faker->streetAddress . " - " .
                    $faker->city . " - " .
                    $faker->postcode . " - " .
                    $faker->state
                ?>
            </p>
        </div>
        <? if ($faker->randomDigit() % 2): ?>
        <progress id="file" max="100" value="<?= $faker->numberBetween(0, 100); ?>"></progress>
        <div class="card-timers">
            <span class="card-timer" style="display: none;"><?= $faker->dateTimeBetween('+2 weeks', '+6 weeks', null)->getTimestamp(); ?></span>
            <span class="card-timer">-- days</span>
            <span class="card-timer">-- hours</span>
            <span class="card-timer">-- minutes</span>
        </div>
        <? else: ?>
        <div class="card-buttons">
            <a href="/files/<?= $faker->regexify('[a-zA-Z0-9]{9}'); ?>" class="card-button">access</a>
        </div>
        <? endif; ?>
    </div>
    <? endfor; ?>
</div>
