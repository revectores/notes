# Python Library `Faker`

##### # Provider

`Faker` is a Python fake data generator.

```python
from faker import Faker
fake = Faker()
```

We can generate random name, address, text...

```python
fake.name()
fake.address()
fake.text()
```

We can import more **providers** from `faker.providers` to generate more properties:

```python
from faker.providers import internet
fake.add_provider(internet)
print(fake.ipv4_private(), fake.http_method())
```

Normally each of the providers packages more than one property, for instance, provider `internet` provides `ipv4_private`, `http_method`, and many other internet-related properties. Available standard providers are listed [here](https://faker.readthedocs.io/en/stable/providers.html).



##### # Localization

`faker.Faker` can take a locale or a list of locales as an argument to return localized data. If no localized provider is found, the factory falls back to the deafult `en_US` locale.

```python
fake = Faker(['en_US', 'ja_JP', 'zh_CN'])
for _ in range(5):
  print(fake.name(), fake.address())
```

Available localized providers are listed [here](https://faker.readthedocs.io/en/master/locales.html).



##### # Weighting

The Faker constructor takes boolean argument `use_weighting` which specifies whether to attempt to have the frequency of values match the real-world frequencies (otherwise executes equal probability of selection). The default is `True`.
