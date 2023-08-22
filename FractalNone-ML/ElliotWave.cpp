#include <torch/torch.h>
#include <iostream>


class MonoWave{
    private:
    torch::Tensor LowPriceData;
    torch::Tensor HighPriceData;
    torch::Tensor ClosePriceData;
    int SkippingValue;
    int IdxStart;
    int IdxEnd;
    int Count;
    int Degree = 1; 
    std::string date_start;
    std::string date_end;
    float LowestPrice;
    float HighestPrice;
    int LowIDX;
    int HighIDX;

    void init(torch::Tensor LowPriceData,torch::Tensor ClosePriceData,torch::Tensor HighPriceData,
              int IdxStart,int SkippingValue){
        this->LowPriceData =LowPriceData;
        this->ClosePriceData = ClosePriceData;
        this->HighPriceData = HighPriceData;
        this->IdxStart =IdxStart;
    }
    
    int ReturnLabel(){
        return this->Count;
    }
    float ReturnLength(){
        return this->HighestPrice - this->LowestPrice ;
    }
    int Duration(){
        return this->IdxEnd- this->IdxStart;
    }
    
    torch::Tensor from_wavepattern(MonoWave (*cls)(torch::Tensor,torch::Tensor,torch::Tensor,int) , MonoWave wave_pattern){//needto vhange
        torch::Tensor lows = torch::zeros(10),  highs =torch::zeros(10), dates= torch::zeros(10);

        if (len(wave_pattern.keys()) == 5){
            this->LowPriceData = wave_pattern.waves.get('wave1').low;
            this->LowIDX = wave_pattern.waves.get('wave1').low_idx;
            this->HighPriceData = wave_pattern.waves.get('wave5').high;
            this->HighIDX = wave_pattern.waves.get('wave5').high_idx;
            date_start = wave_pattern.waves.get('wave1').date_start;
            date_end = wave_pattern.waves.get('wave5').date_end;

            MonoWave monowave_up = cls(lows, highs, dates, 0);

            monowave_up.low, monowave_up.low_idx, monowave_up.high, monowave_up.high_idx = low, low_idx, high, high_idx;
            monowave_up.date_start, monowave_up.date_end = date_start, date_end;

            monowave_up.degree = wave_pattern.waves.get('wave1').degree + 1;
            return monowave_up;
        }
        else if (len(wave_pattern.waves.keys()) == 3){
            low = wave_pattern.waves.get('wave3').low;
            low_idx = wave_pattern.waves.get('wave3').low_idx;
            high = wave_pattern.waves.get('wave1').high;
            high_idx = wave_pattern.waves.get('wave1').high_idx;
            date_start = wave_pattern.waves.get('wave1').date_start;
            date_end = wave_pattern.waves.get('wave3').date_end;

            monowave_down = cls(lows, highs, dates, 0);
            monowave_down.low, monowave_down.low_idx, monowave_down.high, monowave_down.high_idx = low, low_idx, high, high_idx;
            monowave_down.date_start, monowave_down.date_end = date_start, date_end;

            monowave_down.degree = wave_pattern.waves.get('wave1').degree + 1;

            return monowave_down;
        }
    }

}  

class MonoWaveUp(MonoWave):

    def find_end(self){
        high, high_idx = hi(self.lows_arr, self.highs_arr, self.idx_start)
        low_at_start = self.lows_arr[self.idx_start]

        if high is None:
            return None, None;

        for (int i=0;i<skip_n;i++){

            act_high, act_high_idx = next_hi(self.lows_arr, self.highs_arr, high_idx, high)
            if act_high is None:
                return None, None;

            if act_high > high{
                this->high = act_high;
                this->high_idx = act_high_idx;
                if np.min(self.lows_arr[self.idx_start:act_high_idx] < low_at_start)
                    return None, None;
            
        }
        return high, high_idx
        }

  
    def dates(self){
        return (self.date_start, self.date_end);
    }
   
    torch::Tensor points(){
        return (self.low, self.high);
    }


class MonoWaveDown(MonoWave):

   
    def dates(self) -> list:
        return [self.date_start, self.date_end];

   
    def points(self):
        return self.high, self.low

    def find_end(self):

        low, low_idx = lo(self.lows_arr, self.highs_arr, self.idx_start)
        high_at_start = self.highs_arr[self.idx_start]
        if low is None:
            return None, None

        for _ in range(self.skip_n):
            act_low, act_low_idx = next_lo(self.lows_arr, self.highs_arr, low_idx, low)
            if act_low is None:
                return None, None

            if act_low < low:
                low = act_low
                low_idx = act_low_idx
                if np.max(self.highs_arr[self.idx_start:act_low_idx]) > high_at_start:
                    return None, None

        return low, low_idx

class WaveCycle{
 private:
       torch::Tensor wp_up;
        torch::Tensor wp_down;
        torch::Tensor degree;
        std::vector <torch::Tensor> waves =  ;
    
    void Init(wavepattern_up: WavePattern, wavepattern_down: WavePattern):
        wp_up = wavepattern_up;
        wp_down = wavepattern_down;
        degree = wp_up.degree;
        extract_waves();
    
    int end_idx(self):
        return this->wp_down.end_idx

   
    int start_idx(self):
        return this->wp_up.start_idx

    MonoWave extract_waves(self):
        for key, wave in self.wp_up.waves:
            self.waves.append(wave)

        for key, wave in self.wp_down.waves.items():
            self.waves.append(wave)

    def dates(self):
        dates = self.wp_up.dates
        dates.extend(self.wp_down.dates)
        return dates

    def values(self):
        values = self.wp_up.values
        values.extend(self.wp_down.values)
        return values;

   
    def labels(self):
        labels = self.wp_up.labels;
        labels.extend(self.wp_down.labels);
        return labels;


    def __eq__(self, other):
        if (self.wp_down.values == other.wp_down.values) &&( self.wp_up.values == other.wp_up.values)
            return true;
        else
        return false;

    def __hash__(self):
        str_to_hash = f'{self.wp_up.values}_{self.wp_down.values}
        return hash(str_to_hash);

}



